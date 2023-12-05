#include "Transform.h"

Transform::Transform()
	:mPosition(Vector2(0, 0)), mRotation(0)
{
}

Transform::Transform(const Vector2& initialPosition)
	:mPosition(initialPosition), mRotation(0)
{
	
}

Transform::~Transform()
{
}

Vector2 Transform::GetPosition()
{
	return mPosition;
}

float Transform::GetRotation()
{
	return mRotation;
}

Vector2 Transform::GetScale()
{
	return mScale;
}

Vector2 Transform::GetUp()
{
	return mUp;
}

Vector2 Transform::GetRight()
{
	return mRight;
}

void Transform::SetPosition(const Vector2& position)
{
	mPosition = position;
}

void Transform::SetRotation(float rotation)
{
	mRotation = rotation;
	HandleDirection();
}

void Transform::SetScale(const Vector2& scale)
{
	mScale = scale;
}

void Transform::SetUp(const Vector2& up)
{
	float angle = Vector2::FindAngle(mUp,up);
	Rotate(angle);
}

void Transform::SetRight(const Vector2& right)
{
	float angle = Vector2::FindAngle(mRight, right);
	Rotate(angle);
}

void Transform::Translate(const Vector2& translateVector)
{
	Vector2 newPosition = mPosition + translateVector;
	SetPosition(newPosition);
}

void Transform::Rotate(const float& rotationValue)
{
	float newRotation = mRotation + rotationValue;
	SetRotation(newRotation);
}

void Transform::LookAt(Vector2 lookDirection)
{
	float angle = Vector2::FindAngle(Vector2::UP, lookDirection);
	SetRotation(angle);
}

void Transform::HandleDirection()
{
	mUp = Vector2::UP;
	mUp.Rotate(mRotation);

	mRight = Vector2::RIGHT;
	mRight.Rotate(mRotation);
}
