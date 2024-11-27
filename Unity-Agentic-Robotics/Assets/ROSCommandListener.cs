using UnityEngine;
using RosMessageTypes.Geometry;
using Unity.Robotics.ROSTCPConnector;
using Unity.Robotics.ROSTCPConnector.ROSGeometry;

public class ROSCommandListener : MonoBehaviour
{
    public GameObject pickObject;  // Assign PickObject in Unity Inspector
    public GameObject gripper;    // Assign Gripper in Unity Inspector
    public GameObject placeObject; // Assign PlaceObject in Unity Inspector

    private ROSConnection ros;
    private bool isHoldingObject = false;

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();
        ros.Subscribe<PoseMsg>("robot_move_command", OnCommandReceived);
    }

    void OnCommandReceived(PoseMsg command)
    {
        // Convert the ROS position to Unity world position
        Vector3 targetPosition = command.position.From<FLU>();
        
        // Check if it's picking up the object
        if (!isHoldingObject)
        {
            // Move gripper to pickObject
            gripper.transform.position = pickObject.transform.position;
            pickObject.transform.parent = gripper.transform;  // Make the object a child of the gripper
            isHoldingObject = true;
        }
        else
        {
            // Move gripper to placeObject
            gripper.transform.position = placeObject.transform.position;
            pickObject.transform.parent = null;  // Release the object
            pickObject.transform.position = placeObject.transform.position;
            isHoldingObject = false;
        }
    }
}
