// The script enables objects to: Store and reset their initial position and orientation. Attach to and detach from the robotic gripper. Track whether the object has been placed.

using UnityEngine;

public class PickableObject : MonoBehaviour
{
    public bool IsPlaced = false;
    private Transform originalParent;
    private Vector3 initialPosition;
    private Quaternion initialRotation;

    private void Awake()
    {
        // Store the initial position and rotation
        initialPosition = transform.position;
        initialRotation = transform.rotation;
        originalParent = transform.parent;
    }

    public void StoreInitialPosition()
    {
        initialPosition = transform.position;
        initialRotation = transform.rotation;
        originalParent = transform.parent;
    }

    public void ResetToInitialPosition()
    {
        transform.SetParent(originalParent);
        transform.position = initialPosition;
        transform.rotation = initialRotation;
       // GetComponent<Rigidbody>().isKinematic = false;
        IsPlaced = false;
    }

    public void Attach()
    {
        // Assuming the gripper has a GameObject named "Gripper"
        Transform gripper = GameObject.Find("targetobject").transform;
        transform.SetParent(gripper);
        transform.localPosition = Vector3.zero;
         //transform.localRotation = Quaternion.identity; // for rotation of object
       // GetComponent<Rigidbody>().isKinematic = true;
    }

    public void Detach()
    {
        transform.SetParent(null);
       // GetComponent<Rigidbody>().isKinematic = false;
    }
}
