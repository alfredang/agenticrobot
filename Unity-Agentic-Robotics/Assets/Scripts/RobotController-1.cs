using UnityEngine;
using System.Collections;
using System.Collections.Generic;  // Add this line to resolve the List<T> issue

public class RobotController : MonoBehaviour
{
    public Transform shoulderTarget;  // The target for the shoulder to aim at
    public Transform elbowTarget;     // The target for the elbow to aim at (optional, for more control)
    public Transform gripperLeft, gripperRight;  // Gripper parts

    private bool isGripping = false;  // Control whether the gripper is open or closed

    // Move the targets for the arm joints to a specified position
    public IEnumerator MoveToTarget(Vector3 targetPosition)
    {
        Debug.Log($"Moving IK targets to position: {targetPosition}");

        float speed = 1.0f;  // Movement speed
        float step = speed * Time.deltaTime;

        // Move the shoulder target (and optionally the elbow target) towards the target position
        while (Vector3.Distance(shoulderTarget.position, targetPosition) > 0.01f)
        {
            shoulderTarget.position = Vector3.MoveTowards(shoulderTarget.position, targetPosition, step);

            // If you're controlling the elbow separately, you could also move its target:
            // elbowTarget.position = Vector3.MoveTowards(elbowTarget.position, targetPosition, step);

            yield return null;  // Wait for the next frame
        }

        Debug.Log("Arrived at target position.");
        yield return new WaitForSeconds(1);  // Simulate gripping or picking up

        // After reaching the target, grip the object
        StartCoroutine(GripObject());
    }

    // Simulate gripping the object (closing the gripper)
    public IEnumerator GripObject()
    {
        Debug.Log("Gripping object...");

        // Simulate closing the gripper (adjust local positions of the left and right parts)
        for (float t = 0; t < 1f; t += Time.deltaTime)
        {
            gripperLeft.localPosition = Vector3.Lerp(gripperLeft.localPosition, new Vector3(-0.02f, 0, 0), t);  // Example closing motion
            gripperRight.localPosition = Vector3.Lerp(gripperRight.localPosition, new Vector3(0.02f, 0, 0), t);  // Example closing motion
            yield return null;
        }

        isGripping = true;
        Debug.Log("Object gripped.");
    }

    // Simulate releasing the object (opening the gripper)
    public IEnumerator ReleaseObject()
    {
        Debug.Log("Releasing object...");

        // Simulate opening the gripper
        for (float t = 0; t < 1f; t += Time.deltaTime)
        {
            gripperLeft.localPosition = Vector3.Lerp(gripperLeft.localPosition, new Vector3(-0.04f, 0, 0), t);  // Example opening motion
            gripperRight.localPosition = Vector3.Lerp(gripperRight.localPosition, new Vector3(0.04f, 0, 0), t);  // Example opening motion
            yield return null;
        }

        isGripping = false;
        Debug.Log("Object released.");
    }

    // Example function to pick and place objects
    public IEnumerator PickAndPlaceObjects()
    {
        Debug.Log("Picking and placing objects...");

        // Detect objects within range (similar to your previous script)
        Collider[] hitColliders = Physics.OverlapSphere(shoulderTarget.position, 1.0f);
        List<GameObject> detectedObjects = new List<GameObject>();

        // Collect all detected objects
        foreach (Collider hitCollider in hitColliders)
        {
            if (hitCollider.CompareTag("objects"))
            {
                detectedObjects.Add(hitCollider.gameObject); // Add the detected objects to the list
            }
        }

        // Predefined table positions for placing objects
        List<Vector3> tablePositions = new List<Vector3>
        {
            new Vector3(-0.5f, 0.8f, 0.5f),
            new Vector3(-0.5f, 0.8f, 0.3f),
            new Vector3(-0.5f, 0.8f, 0.1f)
        };

        int placedCount = 0;

        foreach (GameObject obj in detectedObjects)
        {
            if (placedCount >= tablePositions.Count)
            {
                Debug.LogWarning("No more available positions on the table.");
                break;
            }

            // Move the shoulder target to the object's position
            yield return StartCoroutine(MoveToTarget(obj.transform.position));

            // Simulate gripping the object
            yield return StartCoroutine(GripObject());

            // Move the shoulder target to the table position
            yield return StartCoroutine(MoveToTarget(tablePositions[placedCount]));

            // Simulate releasing the object
            yield return StartCoroutine(ReleaseObject());

            placedCount++;  // Move to the next table position for the next object
        }

        Debug.Log("Pick and place operation completed.");
    }
}

