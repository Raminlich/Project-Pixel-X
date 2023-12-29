#pragma once
#include "ObjectManager.h"
#include "Component.h"
#include "Vector.h"

#include <iostream>
#include <vector>

class Transform : public Component
{
private:
	Vector2 mGlobalPosition; //World position of object
	float mGlobalRotation = 0.0f; //World Rotation of object
	Vector2 mGlobalScale = Vector2(1, 1); //World scale of object

	Vector2 mUp = Vector2::UP; //Up vector of object
	Vector2 mRight = Vector2::RIGHT; //Right vector of object

	Transform* mParent; //Parent Transform
	std::vector<Transform*> mChildrenTransform; //Vector of children Transform

public:

	Transform(GameObject* gameObject, const Vector2& initialPosition, float initialRotation, Transform* parentTransform = nullptr);

	~Transform();

	void Update() override;

	//Get parent of object
	const Transform* const GetParent();

	//Get position of object
	Vector2 GetPosition();

	//Get local position of object
	Vector2 GetLocalPosition();

	//Get rotation of object
	float GetRotation();

	//Get local rotation of object
	float GetLocalRotation();

	//Get scale of object
	Vector2 GetScale();

	//Get local scale of object
	Vector2 GetLocalScale();

	//Get local up vector of object
	Vector2 GetUp();

	//Get local right vector of object
	Vector2 GetRight();

	//Set position of object
	void SetPosition(const Vector2& position);

	//Set local position of object
	void SetLocalPosition(const Vector2& position);

	//Set rotation of object
	void SetRotation(float rotation);

	//Set local rotation of object
	void SetLocalRotation(float rotation);

	//Set scale of object
	void SetScale(const Vector2& scale);

	//Set local scale of object
	void SetLocalScale(const Vector2& scale);

	//Set up vector of object
	void SetUp(const Vector2& up);

	//Set right vector of object
	void SetRight(const Vector2& right);

	//Set parent for our transform
	void SetParent(Transform* newParentTransform);

	//Returns all childrens of object
	const std::vector<Transform*>& GetChilderen();

	//Move with the translateVector
	void Translate(const Vector2& translateVector);

	//Rotate around center
	void Rotate(const float& rotationValue);

	//Rotate to look at given direction
	void LookAt(Vector2 lookDirecton);

	//Handle Up and Right vector based on rotation
	void HandleDirection();
};

