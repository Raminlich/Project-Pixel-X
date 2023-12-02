#include "Transform.h"

Transform::Transform()
	:position(Vector2(0,0))
{
}

Transform::Transform(const Vector2& initialPosition)
	:position(initialPosition)
{
	
}

Transform::~Transform()
{
}

void Transform::Translate(const Vector2& translateVector)
{
	position = position + translateVector;
}