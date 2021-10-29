#pragma once

#include "UnitSettings.h"

class Unit
{
public:
	Unit(const Vector2& position, const Vector2& viewDirection, const UnitSettings& settings)
		: position(position), viewDirection(viewDirection), distance(settings.distance), sqrDistance(settings.sqrDistance)
	{
		leftDirection = viewDirection * settings.leftRot;
		rightDirection = viewDirection * settings.rightRot;
	}

	Vector2 GetPosition() const { return position; }
	Vector2 GetLeftDirection() const { return leftDirection; }
	Vector2 GetRightDirection() const { return rightDirection;  }
	float GetViewDistance() const { return distance; }
	float GetSqrViewDistance() const { return sqrDistance; }

private:
	Vector2 position;
	Vector2 viewDirection;
	Vector2 leftDirection;
	Vector2 rightDirection;
	float distance;
	float sqrDistance;
};