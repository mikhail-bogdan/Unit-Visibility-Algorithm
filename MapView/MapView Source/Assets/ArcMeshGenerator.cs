using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

[RequireComponent(typeof(MeshFilter), typeof(MeshRenderer))]
public class ArcMeshGenerator : MonoBehaviour
{

    public static Mesh arcMesh;

    public float fieldOfViewAngle;
    public float fieldOfViewDistance;
    public float steps = 10;


    void Start()
    {
        Quaternion leftRot = Quaternion.Euler(0, 0, 135.5f / 2f);
        Quaternion rightRot = Quaternion.Inverse(leftRot);

        Quaternion step = Quaternion.Euler(0, 0, -135.5f / steps);

        List<Vector3> verticles = new List<Vector3>();
        List<int> indices = new List<int>();

        arcMesh = new Mesh();

        verticles.Add(Vector3.zero);

        for (int i = 1; i < steps + 1; i++)
        {
            verticles.Add(leftRot * Vector3.right * fieldOfViewDistance);
            
            indices.Add(0);
            indices.Add(i);
            indices.Add(i + 1);

            leftRot *= step;
        }

        verticles.Add(rightRot * Vector3.right * fieldOfViewDistance);

        arcMesh.vertices = verticles.ToArray();
        arcMesh.triangles = indices.ToArray();

        GetComponent<MeshFilter>().sharedMesh = arcMesh;
    }


    void Update()
    {

    }
}
