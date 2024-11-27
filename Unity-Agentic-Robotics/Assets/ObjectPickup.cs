using UnityEngine;

public class ObjectPickup : MonoBehaviour
{
    private Transform originalParent;

    public void Attach()
    {
        originalParent = transform.parent;
        // Assuming the robotic arm has a GameObject named "Gripper"
        Transform gripper = GameObject.Find("targetobject").transform;
        transform.SetParent(gripper);
        transform.localPosition = Vector3.zero;
        transform.localRotation = Quaternion.identity;
    }

    public void Detach()
    {
        transform.SetParent(originalParent);
    }
}
