using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using System.IO;
using UnityEngine;
using System.Globalization;

public class UnitPlacer : MonoBehaviour
{
    [SerializeField]
    private GameObject unitPrefab;

    private List<UnitBehaviour> units;

    public void MarkUnvisibleAll()
    {
        foreach (UnitBehaviour unit in units)
            unit.MarkUnvisible();
    }

    public void MarkVisibleUnits(UnitBehaviour unit)
    {
        foreach(UnitBehaviour anotherUnit in units)
        {
            if (anotherUnit == unit) continue;

            Vector2 anotherUnitPos = anotherUnit.transform.position - unit.transform.position;

            if (LineFunctions.IsPointOnRightOfLine(unit.leftDirection, anotherUnitPos)
                && LineFunctions.IsPointOnLeftOfLine(unit.rightDirection, anotherUnitPos)
                && anotherUnitPos.SqrMagnitude() <= unit.sqrDistance)
            {
                anotherUnit.MarkVisible();
            }
        }
    }

    void Start()
    {
        units = new List<UnitBehaviour>();

        NumberFormatInfo info = new NumberFormatInfo();
        info.NumberDecimalSeparator = ".";
        info.NumberGroupSeparator = ",";
        info.CurrencyDecimalSeparator = ".";
        info.CurrencyGroupSeparator = ",";

        StreamReader reader = new StreamReader("./units.txt");
        int unitsCount = int.Parse(reader.ReadLine());
        for (int i = 0; i < unitsCount; i++)
        {
            string[] lines = reader.ReadLine().Split(' ');

            Vector3 position = new Vector3(float.Parse(lines[0], info), float.Parse(lines[1], info));
            Vector2 direction = new Vector2(float.Parse(lines[2], info), float.Parse(lines[3], info));
            Quaternion viewDirection = Quaternion.Euler(0, 0, Vector2.Angle(Vector2.right, direction));
            GameObject tmp = Instantiate(unitPrefab, position, Quaternion.identity);
            tmp.transform.GetChild(0).localRotation = viewDirection;
            tmp.GetComponentInChildren<Text>().text = position.x + ":" + position.y;
            UnitBehaviour unit = tmp.GetComponent<UnitBehaviour>();
            unit.viewDirection = direction;
            units.Add(unit);
        }
    }


    void Update()
    {

    }
}
