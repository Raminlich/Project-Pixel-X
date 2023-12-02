#pragma once
#include "Component.h"
#include "Vector.h"

#include <iostream>

class Transform : public Component 
{
public:
	Vector2 position;

	Transform();
	Transform(const Vector2& initialPosition);
	~Transform();

	void Translate(const Vector2& translateVector);
};

