#pragma once

struct Vector2
{
	float x, y;

	Vector2(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	Vector2 operator + (const Vector2& givenVector)
	{
		return Vector2(x + givenVector.x, y + givenVector.y);
	}

	Vector2 operator * (const float& multiplyValue)
	{
		return Vector2(x * multiplyValue, y * multiplyValue);
	}
};

