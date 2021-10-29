using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UnitBehaviour : MonoBehaviour
{
    [SerializeField]
    private GameObject fieldOfView;
    [SerializeField]
    private MeshRenderer render;

    [SerializeField]
    private Material defaultMaterial;
    [SerializeField]
    private Material selectedMaterial;
    [SerializeField]
    private Material visibleMaterial;
    [SerializeField]
    private ArcMeshGenerator meshGenerator;


    public Vector2 viewDirection;
    public Vector2 leftDirection;
    public Vector2 rightDirection;
    public float distance;
    public float sqrDistance;

    public void Start()
    {
        render.material = defaultMaterial;
        fieldOfView.SetActive(false);

        distance = meshGenerator.fieldOfViewDistance;
        sqrDistance = distance * distance;
        Quaternion leftRot = Quaternion.Euler(0, 0, 135.5f / 2f);
        Quaternion rightRot = Quaternion.Inverse(leftRot);
        leftDirection = leftRot * viewDirection;
        rightDirection = rightRot * viewDirection;
    }

    public void ShowFieldOfView()
    {
        fieldOfView.SetActive(true);
    }

    public void HideFieldOfView()
    {
        fieldOfView.SetActive(false);
    }

    public void Select()
    {
        ShowFieldOfView();
        render.material = selectedMaterial;
    }

    public void UnSelect()
    {
        HideFieldOfView();
        render.material = defaultMaterial;
    }

    public void MarkVisible()
    {
        render.material = visibleMaterial;
    }

    public void MarkUnvisible()
    {
        render.material = defaultMaterial;
    }
}
