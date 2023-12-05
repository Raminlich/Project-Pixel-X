#pragma once
#include "Component.h"
#include "Vector.h"

#include <cmath>
#include <iostream>

class Transform : public Component 
{
private :
	Vector2 mPosition; //Position of object in world
	float mRotation = 0.0f; //Rotation of object in world
	Vector2 mScale = Vector2(1, 1); //Scale of object in world

	Vector2 mUp = Vector2::UP; //Local up vector of object
	Vector2 mRight = Vector2::RIGHT; //Local right vector of object

public:
	Transform();
	Transform(const Vector2& initialPosition);
	~Transform();

	//Get position of object
	Vector2 GetPosition();

	//Get rotation of object
	float GetRotation();

	//Get scale of object
	Vector2 GetScale();

	//Get local up vector of object
	Vector2 GetUp();

	//Get local right vector of object
	Vector2 GetRight();

	//Set position of object
	void SetPosition(const Vector2& position);

	//Set rotation of object
	void SetRotation(float rotation);

	//Set scale of object
	void SetScale(const Vector2& scale);

	//Set up vector of object
	void SetUp(const Vector2& up);

	//Set right vector of object
	void SetRight(const Vector2& right);

	//Move with the translateVector
	void Translate(const Vector2& translateVector);

	//Rotate around center
	void Rotate(const float& rotationValue);

	//Rotate to look at given direction
	void LookAt(Vector2 lookDirecton);

	void HandleDirection();
};

