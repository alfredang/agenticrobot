using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;
using ROSStringMsg = RosMessageTypes.Std.StringMsg; // Alias for convenience
using RosMessageTypes.My; // Adjust the namespace to match your setup

// Class Structure
namespace Unity.Robotics.UrdfImporter.Control
{
    public class RoboticArmController : MonoBehaviour
    {
        // Serializable class to hold joint references and target angles
        [Serializable]
        public class JointTarget
        {
            public ArticulationBody joint;
            public float targetAngle; // In degrees
        }

        // Class to represent a pick or drop position
        [Serializable]
        public class Position
        {
            public string positionName;
            public List<JointTarget> jointTargets;

            // Detection Transform (could be an empty GameObject at the position)
            public Transform detectionPoint;

            // Detection Radius
            public float detectionRadius = 0.1f;

            // Is the drop position occupied?
            public bool IsOccupied = false;
        }
	
	// Variables and Settings
        [Header("Pick Positions")]
        [Tooltip("List of predefined pick positions")]
        public List<Position> pickPositions;

        [Header("Drop Positions")]
        [Tooltip("List of predefined drop positions")]
        public List<Position> dropPositions;

        [Header("Robotic Arm Settings")]
        [Tooltip("Speed at which joints move to their targets (degrees per second)")]
        public float moveSpeed = 30.0f;
        private bool jointMoving;

        [Header("Default Position")]
        [Tooltip("Default position of the robotic arm")]
        public Position defaultPosition;

        [Header("Gripper Settings")]
        [Tooltip("Left Gripper Joint")]
        public ArticulationBody leftGripperJoint;
        [Tooltip("Right Gripper Joint")]
        public ArticulationBody rightGripperJoint;

        [Tooltip("Gripper Closed Position (degrees)")]
        public float gripperClosedPosition = 0.0f;

        [Tooltip("Gripper Open Position for Picking (degrees)")]
        public float gripperOpenPosition_Pick_Left = 0.01f;
        public float gripperOpenPosition_Pick_Right = -0.01f;

        [Tooltip("Gripper Open Positions for Dropping (degrees)")]
        public float gripperOpenPosition_Drop1_Left = 0.001f;
        public float gripperOpenPosition_Drop1_Right = -0.001f;
        public float gripperOpenPosition_Drop2_Left = 0.0f;
        public float gripperOpenPosition_Drop2_Right = 0.0f;

        private int objectsPickedCount = 0;

        // List to keep track of all pickable objects
        private List<PickableObject> allPickableObjects = new List<PickableObject>();

        [Header("Placement Order Settings")]
        [Tooltip("Place objects from last drop position to first if true")]
        public bool placeInReverseOrder = false;

        // ROS Connector
        private ROSConnection ros;

        private void Start()
        {
            // Find all pickable objects in the scene
            PickableObject[] pickableObjects = FindObjectsOfType<PickableObject>();
            allPickableObjects.AddRange(pickableObjects);

            // Store the initial positions of all pickable objects for resetting
            foreach (var obj in allPickableObjects)
            {
                obj.StoreInitialPosition();
            }

            // Initialize ROS connection
            ros = ROSConnection.GetOrCreateInstance();
            ros.Subscribe<PickAndPlaceCommandMsg>("pick_and_place_command", ExecuteCommand);

            // Register publisher for feedback messages
            ros.RegisterPublisher<ROSStringMsg>("robot_feedback");
        }

	// Command Handling: Processes commands based on command_type
        private void ExecuteCommand(PickAndPlaceCommandMsg cmd)
        {
            Debug.Log($"Received command: {cmd.command_type}::{cmd.object_id}::{cmd.left_to_right}");

            switch (cmd.command_type)
            {
                case "pick_all":
                    placeInReverseOrder = !cmd.left_to_right;  // left to right bool
                    StartCoroutine(PickAllObjectsRoutine());
                    break;
                case "pick_specific":
                    StartCoroutine(PickSpecificObjectRoutine(cmd.object_id));
                    break;
                case "count_objects":
                    CountObjects();
                    break;
                case "list_objects":
                    ListObjects();
                    break;
                default:
                    Debug.LogWarning($"Unknown command type: {cmd.command_type}");
                    break;
            }
        }

        // Function to list all objects and their placement status
        public void ListObjects()
        {
            string message = $"Total objects: {allPickableObjects.Count}\n";
            foreach (PickableObject obj in allPickableObjects)
            {
                message += $"Object: {obj.name}, IsPlaced: {obj.IsPlaced}\n";
            }
            Debug.Log(message);

            // Send feedback back to ROS
            var feedbackMsg = new ROSStringMsg { data = message };
            ros.Publish("robot_feedback", feedbackMsg);
        }

        // Function 1: Pick All Objects
        public void PickAllObjects()
        {
            StartCoroutine(PickAllObjectsRoutine());
        }

        private IEnumerator PickAllObjectsRoutine()
        {
            Debug.Log("Starting to pick all objects.");

            for (int i = 0; i < pickPositions.Count; i++)
            {
                Position pickPosition = pickPositions[i];

                // Detect if there's an object at the pick position
                PickableObject obj = DetectObjectAtPosition(pickPosition);

                if (obj != null && !obj.IsPlaced)
                {
                    // Move to pick position
                    yield return StartCoroutine(MoveToPosition(pickPosition));

                    // Open Gripper to pick position
                    yield return StartCoroutine(MoveGripperToPosition(gripperOpenPosition_Pick_Left, gripperOpenPosition_Pick_Right));

                    // Wait briefly
                    yield return new WaitForSeconds(0.5f);

                    // Close Gripper to pick up the object
                    yield return StartCoroutine(MoveGripperToPosition(gripperClosedPosition, gripperClosedPosition));

                    // Simulate picking up the object
                    Debug.Log($"Picking up object: {obj.name}");
                    obj.Attach();

                    // Send feedback to ROS
                    SendFeedback($"Picking up object: {obj.name}");

                    // Move to default position
                    yield return StartCoroutine(MoveToPosition(defaultPosition));

                    // Find the next available drop position
                    Position dropPosition = GetNextAvailableDropPosition();
                    if (dropPosition == null)
                    {
                        Debug.LogWarning("No available drop positions. Cannot place the object.");
                        yield break;
                    }

                    // Move to drop position
                    yield return StartCoroutine(MoveToPosition(dropPosition));

                    // Open Gripper to drop position (first to 0.001)
                    yield return StartCoroutine(MoveGripperToPosition(gripperOpenPosition_Drop1_Left, gripperOpenPosition_Drop1_Right));

                    // Wait briefly
                    yield return new WaitForSeconds(0.5f);

                    // Open Gripper further to 0.0
                    yield return StartCoroutine(MoveGripperToPosition(gripperOpenPosition_Drop2_Left, gripperOpenPosition_Drop2_Right));

                    // Simulate dropping the object
                    Debug.Log($"Dropping object: {obj.name}");
                    obj.Detach();

                    // Send feedback to ROS about placing the object
                    string side = placeInReverseOrder ? "right" : "left";
                    SendFeedback($"Placing object: {obj.name} from the {side} side of the table");

                    // Wait briefly
                    yield return new WaitForSeconds(0.5f);

                    // Close Gripper back to closed position
                    yield return StartCoroutine(MoveGripperToPosition(gripperClosedPosition, gripperClosedPosition));

                    // Move back to default position after dropping
                    yield return StartCoroutine(MoveToPosition(defaultPosition));

                    // Mark object as placed
                    obj.IsPlaced = true;
                    // Mark drop position as occupied
                    dropPosition.IsOccupied = true;

                    objectsPickedCount++;
                    Debug.Log($"Objects picked so far: {objectsPickedCount}");
                }
                else
                {
                    if (obj == null)
                    {
                        Debug.Log($"No object detected at pick position {pickPosition.positionName}. Skipping.");
                    }
                    else if (obj.IsPlaced)
                    {
                        
                        Debug.Log($"Object {obj.name} at position {pickPosition.positionName} is already placed. Skipping.");
                    }
                }
            }

            Debug.Log("Finished picking all objects.");
        }

        // Function 2: Pick Specific Object
        public void PickSpecificObject(string objectName)
        {
            StartCoroutine(PickSpecificObjectRoutine(objectName));
        }

        private IEnumerator PickSpecificObjectRoutine(string objectName)
        {
            Debug.Log($"Starting to pick specific object: {objectName}");

            // Find the object by name
            PickableObject obj = allPickableObjects.Find(o => o.name.ToLower()== objectName.ToLower());

          //  PickableObject obj = allPickableObjects.FirstOrDefault(o => o.name.ToLower() == objectName.ToLower());


            if (obj != null)
            {
                if (obj.IsPlaced)
                {
                    Debug.LogWarning($"Object {objectName} is already placed.");
                    SendFeedback($"Object {objectName} is already placed.");
                    yield break;
                }

                // Find the pick position where the object is located
                Position pickPosition = FindObjectPickPosition(obj);

                if (pickPosition != null)
                {
                    // Move to pick position
                    yield return StartCoroutine(MoveToPosition(pickPosition));

                    // Open Gripper to pick position
                    yield return StartCoroutine(MoveGripperToPosition(gripperOpenPosition_Pick_Left, gripperOpenPosition_Pick_Right));

                    // Wait briefly
                    yield return new WaitForSeconds(0.5f);

                    // Close Gripper to pick up the object
                    yield return StartCoroutine(MoveGripperToPosition(gripperClosedPosition, gripperClosedPosition));

                    // Simulate picking up the object
                    Debug.Log($"Picking up object: {obj.name}");
                    obj.Attach();

                    // Send feedback to ROS
                    SendFeedback($"Picking up object: {obj.name}");

                    // Move to default position
                    yield return StartCoroutine(MoveToPosition(defaultPosition));

                    // Find the next available drop position
                    Position dropPosition = GetNextAvailableDropPosition();
                    if (dropPosition == null)
                    {
                        Debug.LogWarning("No available drop positions. Cannot place the object.");
                        SendFeedback("No available drop positions. Cannot place the object.");
                        yield break;
                    }

                    // Move to drop position
                    yield return StartCoroutine(MoveToPosition(dropPosition));

                    // Open Gripper to drop position
                    yield return StartCoroutine(MoveGripperToPosition(gripperOpenPosition_Drop1_Left, gripperOpenPosition_Drop1_Right));

                    // Wait briefly
                    yield return new WaitForSeconds(0.5f);

                    // Open Gripper further
                    yield return StartCoroutine(MoveGripperToPosition(gripperOpenPosition_Drop2_Left, gripperOpenPosition_Drop2_Right));

                    // Simulate dropping the object
                    Debug.Log($"Dropping object: {obj.name}");
                    obj.Detach();

                    // Send feedback to ROS about placing the object
                    string side = placeInReverseOrder ? "right" : "left";
                    SendFeedback($"Placing object: {obj.name} from the {side} side of the table");

                    // Wait briefly
                    yield return new WaitForSeconds(0.5f);

                    // Close Gripper back to closed position
                    yield return StartCoroutine(MoveGripperToPosition(gripperClosedPosition, gripperClosedPosition));

                    // Move back to default position after dropping
                    yield return StartCoroutine(MoveToPosition(defaultPosition));

                    // Mark object as placed
                    obj.IsPlaced = true;
                    // Mark drop position as occupied
                    dropPosition.IsOccupied = true;

                    objectsPickedCount++;
                    Debug.Log($"Objects picked so far: {objectsPickedCount}");
                }
                else
                {
                    Debug.LogWarning($"Object {objectName} is not at any known pick position.");
                    SendFeedback($"Object {objectName} is not at any known pick position.");
                }
            }
            else
            {
                Debug.LogWarning($"Object {objectName} not found.");
                SendFeedback($"Object {objectName} not found.");
            }

            Debug.Log("Finished picking specific object.");
        }

        // Function to send feedback messages to ROS
        private void SendFeedback(string message)
        {
            Debug.Log($"Sending feedback to ROS: {message}");
            var feedbackMsg = new ROSStringMsg { data = message };
            ros.Publish("robot_feedback", feedbackMsg);
        }

        // Function 3: Count Objects
        public void CountObjects()
        {
            int unplacedCount = allPickableObjects.FindAll(obj => !obj.IsPlaced).Count;
            string message = $"Total unplaced objects: {unplacedCount}";
            Debug.Log(message);

            // Send feedback to ROS
            var feedbackMsg = new ROSStringMsg { data = message };
            ros.Publish("robot_feedback", feedbackMsg);
        }

        // Function 4: Reset All Objects
        public void ResetAllObjects()
        {
            foreach (PickableObject obj in allPickableObjects)
            {
                obj.ResetToInitialPosition();
                obj.IsPlaced = false;
            }
            foreach (var dropPosition in dropPositions)
            {
                dropPosition.IsOccupied = false;
            }
            objectsPickedCount = 0;
            Debug.Log("All objects have been reset to their starting positions.");

            // Send feedback to ROS
            var feedbackMsg = new ROSStringMsg { data = "All objects have been reset to their starting positions." };
            ros.Publish("robot_feedback", feedbackMsg);
        }

        // Function 5: Debug Current State
        public void DebugCurrentState()
        {
            string message = $"Objects picked: {objectsPickedCount}/{allPickableObjects.Count}\n";
            foreach (PickableObject obj in allPickableObjects)
            {
                message += $"Object: {obj.name}, IsPlaced: {obj.IsPlaced}\n";
            }
            foreach (var dropPosition in dropPositions)
            {
                message += $"Drop Position: {dropPosition.positionName}, IsOccupied: {dropPosition.IsOccupied}\n";
            }
            Debug.Log(message);

            // Send feedback to ROS
            var feedbackMsg = new ROSStringMsg { data = message };
            ros.Publish("robot_feedback", feedbackMsg);
        }

        // Detect if there's an object at the pick position
        private PickableObject DetectObjectAtPosition(Position position)
        {
            Collider[] hitColliders = Physics.OverlapSphere(position.detectionPoint.position, position.detectionRadius);
            foreach (var hitCollider in hitColliders)
            {
                PickableObject obj = hitCollider.GetComponent<PickableObject>();
                if (obj != null && !obj.IsPlaced)
                {
                    return obj;
                }
            }
            return null;
        }

        // Find the pick position where the object is located
        private Position FindObjectPickPosition(PickableObject obj)
        {
            foreach (Position position in pickPositions)
            {
                float distance = Vector3.Distance(position.detectionPoint.position, obj.transform.position);
                if (distance <= position.detectionRadius)
                {
                    return position;
                }
            }
            return null;
        }

        // Find the next available drop position
        private Position GetNextAvailableDropPosition()
        {
            if (placeInReverseOrder)
            {
                for (int i = dropPositions.Count - 1; i >= 0; i--)
                {
                    if (!dropPositions[i].IsOccupied)
                    {
                        return dropPositions[i];
                    }
                }
            }
            else
            {
                for (int i = 0; i < dropPositions.Count; i++)
                {
                    if (!dropPositions[i].IsOccupied)
                    {
                        return dropPositions[i];
                    }
                }
            }
            return null; // No available drop positions
        }

        // Coroutine to move the robotic arm to a specific position
        private IEnumerator MoveToPosition(Position position)
        {
            Debug.Log($"Moving to position: {position.positionName}");

            for (int i = 0; i < position.jointTargets.Count; i++)
            {
                JointTarget jt = position.jointTargets[i];
                if (jt.joint != null)
                {
                    yield return StartCoroutine(MoveJointToTarget(jt.joint, jt.targetAngle));
                }
            }

            Debug.Log($"Reached position: {position.positionName}");
        }

        // Coroutine to move a single joint to its target angle
        private IEnumerator MoveJointToTarget(ArticulationBody joint, float targetAngle)
        {
            if (joint == null)
            {
                Debug.LogError("Joint is null.");
                yield break;
            }

            int dof = joint.dofCount;
            if (dof == 0)
            {
                Debug.LogError($"Joint {joint.name} has zero degrees of freedom.");
                yield break;
            }

            jointMoving = true;

            while (jointMoving)
            {
                ArticulationDrive drive = joint.xDrive;

                // Get current joint position (in degrees)
                float currentAngle = joint.jointPosition[0] * Mathf.Rad2Deg;

                // Move towards target angle
                float newAngle = Mathf.MoveTowards(currentAngle, targetAngle, moveSpeed * Time.deltaTime);
                drive.target = newAngle;
                joint.xDrive = drive;

                // Check if the joint has reached its target
                if (Mathf.Abs(newAngle - targetAngle) <= 0.1f)
                {
                    yield return new WaitForSeconds(0.1f);
                    jointMoving = false;
                }

                yield return null;
            }
        }

        // Coroutine to move the gripper to specific positions
        private IEnumerator MoveGripperToPosition(float leftTargetAngle, float rightTargetAngle)
        {
            bool leftMoving = true;
            bool rightMoving = true;

            while (leftMoving || rightMoving)
            {
                // Left Gripper
                if (leftMoving && leftGripperJoint != null)
                {
                    ArticulationDrive leftDrive = leftGripperJoint.xDrive;
                    float currentLeftAngle = leftGripperJoint.jointPosition[0] * Mathf.Rad2Deg;
                    float newLeftAngle = Mathf.MoveTowards(currentLeftAngle, leftTargetAngle, moveSpeed * Time.deltaTime);
                    leftDrive.target = newLeftAngle;
                    leftGripperJoint.xDrive = leftDrive;

                    if (Mathf.Abs(newLeftAngle - leftTargetAngle) <= 0.01f)
                    {
                        leftMoving = false;
                    }
                }

                // Right Gripper
                if (rightMoving && rightGripperJoint != null)
                {
                    ArticulationDrive rightDrive = rightGripperJoint.xDrive;
                    float currentRightAngle = rightGripperJoint.jointPosition[0] * Mathf.Rad2Deg;
                    float newRightAngle = Mathf.MoveTowards(currentRightAngle, rightTargetAngle, moveSpeed * Time.deltaTime);
                    rightDrive.target = newRightAngle;
                    rightGripperJoint.xDrive = rightDrive;

                    if (Mathf.Abs(newRightAngle - rightTargetAngle) <= 0.01f)
                    {
                        rightMoving = false;
                    }
                }

                yield return null;
            }
        }
    }
}
