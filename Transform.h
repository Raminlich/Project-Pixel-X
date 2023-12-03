#pragma once
#include "Component.h"
#include "Vector.h"

#include <cmath>
#include <iostream>

class Transform : public Component 
{
public:
	Vector2 position; //Position of object in world
	double rotation; //Rotation of object in world

	Vector2 up = Vector2::UP; //Local up vector of object
	Vector2 right = Vector2::RIGHT; //Local right vector of object

	Transform();
	Transform(const Vector2& initialPosition);
	~Transform();

	//Move with the translateVector
	void Translate(const Vector2& translateVector);

	//Rotate around center
	void Rotate(const double& rotationValue);

	//Rotate to look at given direction
	void LookAt(Vector2 lookDirecton);
};

