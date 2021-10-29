#include "Quaternion.h"

#include <cmath>

Quaternion Quaternion::identity = Quaternion(0, 0, 0, 1);


Quaternion Quaternion::Euler(float z)
{
	return Quaternion(0, 0, sin(z / 2), cos(z / 2));
}

Quaternion Quaternion::Normalized() const
{
	Quaternion q(*this);
	return q / q.Magnitude();
}

float Quaternion::Dot(const Quaternion& aQuat) const
{
	return (this->x * aQuat.x + this->y * aQuat.y + this->z * aQuat.z + this->w * aQuat.w);
}

float Quaternion::SqrMagnitude() const
{
	return Dot(*this);
}

float Quaternion::Magnitude() const
{
	return sqrt(this->SqrMagnitude());
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-this->x, -this->y, -this->z, this->w);
}

Quaternion Quaternion::Inverse() const
{
	return this->Conjugate();
}

Quaternion& Quaternion::operator=(const Quaternion& aQuat)
{
	this->x = aQuat.x;
	this->y = aQuat.y;
	this->z = aQuat.z;
	this->w = aQuat.w;
	return *this;
}

Quaternion& Quaternion::operator+=(const Quaternion& aQuat)
{
	this->x += aQuat.x;
	this->y += aQuat.y;
	this->z += aQuat.z;
	this->w += aQuat.w;
	return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& aQuat)
{
	this->x -= aQuat.x;
	this->y -= aQuat.y;
	this->z -= aQuat.z;
	this->w -= aQuat.w;
	return *this;
}

Quaternion& Quaternion::operator*=(float aScalar)
{
	this->x *= aScalar;
	this->y *= aScalar;
	this->z *= aScalar;
	this->w *= aScalar;
	return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& aQuat)
{
	float tempx = w * aQuat.x + x * aQuat.w + y * aQuat.z - z * aQuat.y;
	float tempy = w * aQuat.y + y * aQuat.w + z * aQuat.x - x * aQuat.z;
	float tempz = w * aQuat.z + z * aQuat.w + x * aQuat.y - y * aQuat.x;
	float tempw = w * aQuat.w - x * aQuat.x - y * aQuat.y - z * aQuat.z;
	x = tempx; y = tempy; z = tempz; w = tempw;
	return *this;
}

Quaternion& Quaternion::operator/=(float aScalar)
{
	this->x /= aScalar;
	this->y /= aScalar;
	this->z /= aScalar;
	this->w /= aScalar;
	return *this;
}

Quaternion Quaternion::operator*(float aScalar) const
{
	return Quaternion(x * aScalar, y * aScalar, z * aScalar, w * aScalar);
}

Quaternion Quaternion::operator/(float aScalar) const
{
	return Quaternion(x / aScalar, y / aScalar, z / aScalar, w / aScalar);
}

Quaternion Quaternion::operator*(const Quaternion& bQuat) const
{
	return Quaternion(
		this->w * bQuat.x + this->x * bQuat.w + this->y * bQuat.z - this->z * bQuat.y,
		this->w * bQuat.y + this->y * bQuat.w + this->z * bQuat.x - this->x * bQuat.z,
		this->w * bQuat.z + this->z * bQuat.w + this->x * bQuat.y - this->y * bQuat.x,
		this->w * bQuat.w - this->x * bQuat.x - this->y * bQuat.y - this->z * bQuat.z);
}

Quaternion Quaternion::operator*(const Vector2& bVec) const
{
	return Quaternion(							// Optimized for Vector2. Initial for Vector3:
		this->w * bVec.x - this->z * bVec.y,	// this->w * bVec.x + this->y * bVec.z - this->z * bVec.y,
		this->w * bVec.y + this->z * bVec.x,	// this->w * bVec.y - this->x * bVec.z + this->z * bVec.x,
		this->x * bVec.y - this->y * bVec.x,	// this->w * bVec.z + this->x * bVec.y - this->y * bVec.x,
		-this->x * bVec.x - this->y * bVec.y);	// -this->x * bVec.x - this->y * bVec.y - this->z * bVec.z);
}

Vector2 operator*(const Vector2& aVec, const Quaternion& bQuat)
{
    Quaternion t = bQuat * aVec;
    t *= bQuat.Inverse();

    return Vector2(t.x, t.y);
}
