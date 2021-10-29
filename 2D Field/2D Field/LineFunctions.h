#pragma once

#include "Vector2.h"

class LineFunctions
{
public:
	static inline bool IsPointOnRightOfLine(const Vector2& lineVector, const Vector2& point)
	{
		return CalculatePointRelativeToLine(lineVector, point) <= 0;
	}

	static inline bool IsPointOnLeftOfLine(const Vector2& lineVector, const Vector2& point)
	{
		return CalculatePointRelativeToLine(lineVector, point) >= 0;
	}

	static inline float CalculatePointRelativeToLine(const Vector2& lineVector, const Vector2& point)
	{
		return lineVector.x * point.y - point.x * lineVector.y;
	}
};