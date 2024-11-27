using UnityEngine;
using RosMessageTypes.Std;
using Unity.Robotics.ROSTCPConnector;

public class TestPublisher : MonoBehaviour
{
 ROSConnection ros;
    
    public string publishTopicName = "unity_to_ros_topic";
    public string subscribeTopicName = "ros_to_unity_topic";

    // Frequency of publishing messages in seconds
    public float publishFrequency = 1.0f;

    private float timeElapsed;

    void Start()
    {
        // Get the ROSConnection instance
        ros = ROSConnection.GetOrCreateInstance();
        ros.RegisterPublisher<StringMsg>(publishTopicName);

        // Register a subscriber with a callback function
        ros.Subscribe<StringMsg>(subscribeTopicName, ReceiveMessage);

        // Initialize timer
        timeElapsed = 0;
    }

    void Update()
    {
        timeElapsed += Time.deltaTime;

        // Publish a message at the defined frequency
        if (timeElapsed >= publishFrequency)
        {
            PublishMessage();
            timeElapsed = 0;
        }
    }

    void PublishMessage()
    {
        // Create a new message to send
        StringMsg message = new StringMsg("Hello from Unity to ROS 2!");
        ros.Publish(publishTopicName, message);
        
        Debug.Log($"Sent message to ROS 2: {message.data}");
    }

    void ReceiveMessage(StringMsg message)
    {
        Debug.Log($"Received message from ROS 2: {message.data}");
    }
}
