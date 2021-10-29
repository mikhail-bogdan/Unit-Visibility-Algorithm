#pragma once

#include "Quaternion.h"

const float PI = 3.141592741f;

struct UnitSettings
{
public:
	Quaternion leftRot;
	Quaternion rightRot;
	float distance;
	float sqrDistance;

	UnitSettings(float angle, float distance)
	{
		this->leftRot = Quaternion::Euler(angle * PI / 360.0f);
		this->rightRot = this->leftRot.Inverse();
		this->distance = distance;
		this->sqrDistance = distance * distance;
	}
};