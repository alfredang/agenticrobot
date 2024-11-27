using System.Collections;
using UnityEngine;
using UnityEngine.Networking;

public class RobotChat : MonoBehaviour
{
    private string serverUrl = "http://localhost:5000/chat";

    void Start()
    {
        StartCoroutine(ChatWithServer("Hello, robot!"));
    }

    IEnumerator ChatWithServer(string userInput)
    {
        // Create JSON payload
        string jsonData = JsonUtility.ToJson(new { input = userInput });

        // Create request
        UnityWebRequest request = new UnityWebRequest(serverUrl, "POST");
        byte[] bodyRaw = new System.Text.UTF8Encoding().GetBytes(jsonData);
        request.uploadHandler = new UploadHandlerRaw(bodyRaw);
        request.downloadHandler = new DownloadHandlerBuffer();
        request.SetRequestHeader("Content-Type", "application/json");

        // Send request and wait for response
        yield return request.SendWebRequest();

        if (request.result != UnityWebRequest.Result.Success)
        {
            Debug.LogError("Error: " + request.error);
        }
        else
        {
            // Parse response
            string responseText = request.downloadHandler.text;
            ChatResponse response = JsonUtility.FromJson<ChatResponse>(responseText);
            Debug.Log("Response: " + response.response);
            Debug.Log("Action Result: " + response.action_result);

            // Handle robot actions here if needed
        }
    }
}

[System.Serializable]
public class ChatResponse
{
    public string response;
    public string action_result;
}

