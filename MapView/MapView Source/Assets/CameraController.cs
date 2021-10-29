using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    [SerializeField]
    private UnitPlacer placer;

    [SerializeField]
    private Vector3 startPosition;
    [SerializeField]
    private float cameraSpeed = 0.1f;

    private float cameraSize;

    private UnitBehaviour selectedUnit;

    void Start()
    {
        cameraSize = Camera.main.orthographicSize;
    }


    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
            Application.Quit();

        if (Input.GetKeyDown(KeyCode.R))
        {
            transform.position = startPosition;
            Camera.main.orthographicSize = cameraSize;
        }

        Camera.main.orthographicSize -= Input.GetAxis("Mouse ScrollWheel");
        Camera.main.orthographicSize = Mathf.Clamp(Camera.main.orthographicSize, 0.5f, 8f);

        Vector3 movement = new Vector3(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

        transform.position += movement * Camera.main.orthographicSize * cameraSpeed;

        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;

            if (Physics.Raycast(ray, out hit))
            {
                if (hit.collider.tag.Equals("Unit"))
                {
                    UnitBehaviour tmpUnit = hit.collider.GetComponent<UnitBehaviour>();

                    if (selectedUnit != tmpUnit)
                    {
                        UnSelectUnits();

                        selectedUnit = hit.collider.GetComponent<UnitBehaviour>();
                        selectedUnit.Select();
                        placer.MarkVisibleUnits(selectedUnit);
                        return;
                    }
                }

            }

            UnSelectUnits();
        }
    }

    private void UnSelectUnits()
    {
        if (selectedUnit != null)
            selectedUnit.UnSelect();
        selectedUnit = null;
        placer.MarkUnvisibleAll();
    }
}
