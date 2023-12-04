#include "Transform.h"

Transform::Transform()
	:position(Vector2(0, 0)), rotation(0)
{
}

Transform::Transform(const Vector2& initialPosition)
	:position(initialPosition), rotation(0)
{
	
}

Transform::~Transform()
{
}

void Transform::Translate(const Vector2& translateVector)
{
	position += translateVector;
}

void Transform::Rotate(const double& rotationValue)
{
	rotation += rotationValue;
	up.Rotate(rotationValue);
	right.Rotate(rotationValue);
}

void Transform::LookAt(Vector2 lookDirection)
{
	float angle = Vector2::FindAngle(Vector2::UP, lookDirection);
	rotation = angle;

	HandleDirection();
}

void Transform::HandleDirection()
{
	up = Vector2::UP;
	up.Rotate(rotation);

	right = Vector2::RIGHT;
	right.Rotate(rotation);
}
