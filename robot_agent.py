import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from my_msgs.msg import PickAndPlaceCommand
import openai
import json
import os
import threading
import streamlit as st
from datetime import datetime
from collections import deque
import time

class RobotController(Node): # Class Initialization
    def __init__(self):
        super().__init__('robot_controller')

        # Boolean to determine if OpenAI API should be used
        self.use_openai = True

        # Publisher to send commands to Unity
        self.publisher = self.create_publisher(PickAndPlaceCommand, 'pick_and_place_command', 10)

        # Subscription to receive feedback from Unity
        self.subscription = self.create_subscription(
            String,
            'robot_feedback',
            self.feedback_callback,
            10)

        # Load your OpenAI API key securely
        self.openai_api_key = os.getenv('OPENAI_API_KEY', 'insert_openapi_key')

        # Deque to store last 5 feedback messages
        self.feedback_messages = deque(maxlen=5)

    def feedback_callback(self, msg):
        feedback = f"[{datetime.now().strftime('%H:%M:%S')}] {msg.data}"
        self.feedback_messages.append(feedback)
        self.get_logger().info(f"Received feedback: {msg.data}")

    def interpret_command(self, user_input): #Command Interpretation
        if not self.use_openai:
            return self.manual_command_selection()

        openai.api_key = self.openai_api_key
        try:
            response = openai.ChatCompletion.create(
                model="gpt-3.5-turbo",
                messages=[
                    {"role": "system", "content": "You are an assistant that interprets commands for a robot arm. Respond only with JSON. The JSON keys are:\n"
                                                  "- 'command_type': One of 'pick_all', 'pick_specific', 'count_objects', or 'list_objects'.\n"
                                                  "- 'object_id': The object to pick (only for 'pick_specific').\n"
                                                  "- 'left_to_right': Boolean, true if placing from left to right (only for 'pick_all')."},
                    {"role": "user", "content": user_input}
                ],
                max_tokens=50,
                temperature=0.3
            )
            response_content = response['choices'][0]['message']['content'].strip()
            self.get_logger().info(f"Raw response from OpenAI: {response_content}")
            return json.loads(response_content)
        except Exception as e:
            self.get_logger().error(f"Error interpreting command: {e}")
            return None

    def manual_command_selection(self, command_number, object_id=''):
        command_map = {
            "1": {"command_type": "pick_all", "left_to_right": True},
            "2": {"command_type": "pick_all", "left_to_right": False},
            "3": {"command_type": "pick_specific", "object_id": object_id},
            "4": {"command_type": "count_objects"},
            "5": {"command_type": "list_objects"}
        }
        return command_map.get(command_number, None)

    # Creates a PickAndPlaceCommand message with the appropriate fields and publishes the message to Unity via the pick_and_place_command topic.
    def send_command(self, command_type, object_id="", left_to_right=True): # 
        msg = PickAndPlaceCommand()
        msg.command_type = command_type
        msg.object_id = object_id
        msg.left_to_right = left_to_right
        self.publisher.publish(msg)
        self.get_logger().info(f"Sent command: {command_type}::{object_id}::{left_to_right}")

    def run(self):
        rclpy.spin(self)

# Initialise ROS2 and starts ROS2 Nodes
def main(args=None):
    # Ensure rclpy.init() is called only once
    if "ros_initialized" not in st.session_state:
        rclpy.init(args=args)
        st.session_state["ros_initialized"] = True

    # Ensure RobotController is created only once
    if "robot_controller" not in st.session_state:
        st.session_state["robot_controller"] = RobotController()

    # Start ROS node in a separate thread if not already started
    if "ros_thread" not in st.session_state:
        ros_thread = threading.Thread(target=st.session_state["robot_controller"].run, daemon=True)
        ros_thread.start()
        st.session_state["ros_thread"] = ros_thread

    # Streamlit UI
    st.title("Robotic Arm Controller")
    st.write("Send commands to the robotic arm and view feedback.")

    # Input method selection
    input_method = st.radio("Select input method:", ('OpenAI Natural Language', 'Manual Command Selection'))

    if input_method == 'OpenAI Natural Language':
        st.session_state["robot_controller"].use_openai = True
        user_input = st.text_input("Enter your command:")
        if st.button("Send Command"):
            if user_input.strip() == '':
                st.error("Please enter a command.")
            else:
                interpreted_command = st.session_state["robot_controller"].interpret_command(user_input)
                if interpreted_command is None:
                    st.error("Unable to interpret command.")
                else:
                    command_type = interpreted_command.get('command_type')
                    if command_type == "pick_all":
                        left_to_right = interpreted_command.get("left_to_right", True)
                        st.session_state["robot_controller"].send_command("pick_all", left_to_right=left_to_right)
                    elif command_type == "pick_specific":
                        object_id = interpreted_command.get("object_id", "")
                        st.session_state["robot_controller"].send_command("pick_specific", object_id=object_id)
                    elif command_type == "count_objects":
                        st.session_state["robot_controller"].send_command("count_objects")
                    elif command_type == "list_objects":
                        st.session_state["robot_controller"].send_command("list_objects")
                    else:
                        st.error("Unknown command type received.")
    else:
        st.session_state["robot_controller"].use_openai = False
        command_number = st.selectbox("Select Command:", ["1 - Pick All Objects (Left to Right)",
                                                          "2 - Pick All Objects (Right to Left)",
                                                          "3 - Pick Specific Object",
                                                          "4 - Count Objects",
                                                          "5 - List Objects"])
        command_number = command_number.split(' ')[0]
        object_id = ''
        if command_number == "3":
            object_id = st.text_input("Enter the object ID to pick:")
        if st.button("Send Command"):
            interpreted_command = st.session_state["robot_controller"].manual_command_selection(command_number, object_id)
            if interpreted_command is None:
                st.error("Invalid command selection.")
            else:
                command_type = interpreted_command.get('command_type')
                if command_type == "pick_all":
                    left_to_right = interpreted_command.get("left_to_right", True)
                    st.session_state["robot_controller"].send_command("pick_all", left_to_right=left_to_right)
                elif command_type == "pick_specific":
                    object_id = interpreted_command.get("object_id", "")
                    if object_id == '':
                        st.error("Please enter an object ID.")
                    else:
                        st.session_state["robot_controller"].send_command("pick_specific", object_id=object_id)
                elif command_type == "count_objects":
                    st.session_state["robot_controller"].send_command("count_objects")
                elif command_type == "list_objects":
                    st.session_state["robot_controller"].send_command("list_objects")
                else:
                    st.error("Unknown command type received.")

    # Display feedback messages dynamically
    st.subheader("Feedback from Robot:")
    feedback_display = st.empty()

    while True:
        feedback_list = list(st.session_state["robot_controller"].feedback_messages)
        if feedback_list:
            feedback_display.text("\n".join(feedback_list))
        time.sleep(1)  # Update every second

    # Cleanup
    if st.button("Shutdown ROS"):
        st.session_state["robot_controller"].destroy_node()
        rclpy.shutdown()
        st.session_state.clear()


if __name__ == '__main__':
    main()

