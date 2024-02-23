#pragma once
#include "Component.h"

class GameObject;

class PhysicsHandler : public Component
{
private:


public:
	PhysicsHandler(GameObject* gameObject);
	~PhysicsHandler();
};