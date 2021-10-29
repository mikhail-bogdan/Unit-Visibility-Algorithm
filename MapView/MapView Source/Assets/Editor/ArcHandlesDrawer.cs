using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(ArcMeshGenerator))]
public class ArcHandlesDrawer : Editor
{
    public void OnSceneGUI()
    {
        var t = target as ArcMeshGenerator;
        var tr = t.transform;
        var pos = tr.position;

        int steps = 10;

        Quaternion leftRot = Quaternion.Euler(0, 0, 135.5f / 2f);
        Quaternion rightRot = Quaternion.Inverse(leftRot);

        Quaternion step = Quaternion.Euler(0, 0, -135.5f / steps);

        Handles.color = Color.red;

        for (int i = 0; i < steps; i++)
        {
            Handles.DrawLine(pos, pos + leftRot * Vector3.right);
            leftRot *= step;
        }

        Handles.DrawLine(pos, pos + rightRot * Vector3.right);
    }
}
