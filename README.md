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
   ```bash
   git clone https://github.com/<your-username>/<repository-name>.git
   cd <repository-name>
