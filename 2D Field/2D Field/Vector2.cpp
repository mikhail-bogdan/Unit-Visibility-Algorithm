#include "Vector2.h"

#include <cmath>

Vector2 Vector2::zero = Vector2(0, 0);
Vector2 Vector2::up = Vector2(0, 1);
Vector2 Vector2::down = Vector2(0, -1);
Vector2 Vector2::right = Vector2(1, 0);
Vector2 Vector2::left = Vector2(-1, 0);


float Vector2::Magnitude()
{
    return sqrt(SqrMagnitude());
}

float Vector2::SqrMagnitude()
{
    return x * x + y * y;
}

Vector2 Vector2::operator+(const Vector2& value) const
{
    return Vector2(x + value.x, y + value.y);
}

Vector2 Vector2::operator-(const Vector2& value) const
{
    return Vector2(x - value.x, y - value.y);
}

float Vector2::SqrDistance(const Vector2& a, const Vector2& b)
{
    float diffX = a.x - b.x;
    float diffY = a.y - b.y;
    return (diffY * diffY) + (diffX * diffX);
}
