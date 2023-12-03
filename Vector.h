#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

struct Vector2
{
	float x, y;
	const static Vector2 UP;
	const static Vector2 RIGHT;

	Vector2(int x = 0, int y = 0);
	Vector2 operator + (const Vector2& givenVector);
	Vector2 operator * (float multiplyValue);
	void operator += (const Vector2& givenVector);

	//Returns magnitude of Vector2
	static float Magnitude(const Vector2& vector);
	//Returns dot product of 2 Vector
	static float DotProduct(const Vector2& v1, const Vector2& v2);
	//Returns cross product of 2 Vector
	static float CrossProduct(const Vector2& v1, const Vector2& v2);
	//Find angle between 2 Vector in degrees
	static float FindAngle(const Vector2& v1, const Vector2& v2);
	//Returns Vector2 in SDL coordinate system
	static Vector2 WorldToSDL(const Vector2& v);

	//Rotates vector clockwise in degrees 
	void Rotate(float angle);
	//Normalize our Vector2
	void Normalize();
	//Return Normalized value of Vector2
	Vector2 Nomralized();
};

std::ostream& operator <<(std::ostream& stream, const Vector2& vector2);

