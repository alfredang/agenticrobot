# Agentic Robot Project

This repository contains the source code for an agentic robotic system using Unity, ROS2, and OpenAI. The project simulates a Niryo One robotic arm capable of performing tasks based on user inputs via a smart agent.

## Features
- Unity-based robotic simulation with Niryo One arm.
- ROS2 integration for sending and receiving commands.
- OpenAI-powered agent for interpreting user commands and managing workflows.
- Streamlit interface for dynamic user inputs and real-time feedback.
- Agentic Workflow: The system uses an agentic workflow that dynamically interprets user commands, decides appropriate actions, and invokes tools for detecting, picking, and placing objects. It maintains context across commands for efficient execution of complex tasks.

## Technologies Used
- **Unity 6000.0.28f1**: For robotic simulation.
- **ROS2 Iron**: For communication between Unity and the Python agent.
- **Ubuntu 22.04 LTS**: Stability and compatibility with ROS2
- **OpenAI**: For interpreting user commands and reasoning.
- **Streamlit**: For a user-friendly interface to interact with the robot.

## Repository Structure
- `robot_agent.py`: Python script for the robotic agent.
- `Unity/`: Unity project files for the robotic simulation.
- `ros2_ws/`: ROS2 workspace for communication with Unity.
- `.gitignore`: Ignores Unity-generated and unnecessary files.

## Setup Instructions

### 1. Clone the repository:
- git clone https://github.com/<your-username>/<repository-name>.git
- cd <repository-name>

### 2. Download ROS-TCP-Endpoint
- Download the ROS-TCP-Endpoint package from the official release:
  
- Clone the ROS-TCP-Endpoint Release v0.7.0 in the ros2_ws/src/ directory.
- cd ros2_ws/src/
- git clone https://github.com/Unity-Technologies/ROS-TCP-Endpoint.git

![image](https://github.com/user-attachments/assets/5220c768-2b1c-4ff0-b1bc-bca611282163)

### 3. Install Dependencies
- Ensure your system is set up with the required tools:

- Install ROS2 Iron: Follow the ROS2 Installation Guide here: https://docs.ros.org/en/iron/Installation.html
- Install Unity Hub: https://unity.com/unity-hub
- Install the Unity 6(6000.0.28f1) Editor

![image](https://github.com/user-attachments/assets/3e251e7a-aeee-4486-a06c-d9870f46a19d)

### 4. Build the ROS2 Workspace
- Navigate to the ros2_ws directory and build the workspace:
- cd ros2_ws
- colcon build

### 5. Source the ROS2 Environment
- Before launching ROS2 nodes, source the setup file:
- source install/setup.bash

### 6. Open Unity Project
- Open Unity Hub and load the Unity project named Unity-Agentic-Robotics
- Once the project is open, Navigate to the Package Manager from Unity (Window > Package Manager)
- Ensure ROS-TCP-Connector package is Installed

![image](https://github.com/user-attachments/assets/f735883e-0910-4fa7-9850-1658647b6dc3)

### 7. Run the Entire Program
- To run the entire program, follow these steps:

- Play the Unity Game:
- Open Unity and press the Play button to start the simulation

- Run the TCP Endpoint:
- In a new terminal, navigate to the ROS2 workspace and run the TCP endpoint:
- ros2 run ros_tcp_endpoint default_server_endpoint --ros-args -p ROS_IP:=127.0.0.1

- Run the Python Code:
- In another terminal, navigate to the directory containing the Python script and run it using Streamlit:
- streamlit run robot_agent.py --server.address 0.0.0.0
- Open the URL shown in the terminal (e.g., http://0.0.0.0:8501) in your browser to interact with the Streamlit interface.
