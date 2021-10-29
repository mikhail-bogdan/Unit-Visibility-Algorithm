using UnityEngine;

class LineFunctions
{
    public static bool IsPointOnRightOfLine(Vector2 lineVector, Vector2 point)
    {
        return CalculatePointRelativeToLine(lineVector, point) <= 0;
    }

    public static bool IsPointOnLeftOfLine(Vector2 lineVector, Vector2 point)
    {
        return CalculatePointRelativeToLine(lineVector, point) >= 0;
    }

    static float CalculatePointRelativeToLine(Vector2 lineVector, Vector2 point)
    {
        return lineVector.x * point.y - point.x * lineVector.y;
    }
}