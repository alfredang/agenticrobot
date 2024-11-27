using UnityEngine;
using RosMessageTypes.Std;
using Unity.Robotics.ROSTCPConnector;

public class ROSSubscriber : MonoBehaviour
{
    ROSConnection ros;

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();
        
        ros.Subscribe<StringMsg>("/ros_test_topic", ReceiveMessage);
        Debug.Log("Started Received message from ROS: ");
         
    }


    void ReceiveMessage(StringMsg message)
    {
        Debug.Log("Received message from ROS: " + message.data);
    }
}
