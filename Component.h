#pragma once

class GameObject;

class Component
{
public:
	GameObject* gameObject = nullptr;

	Component(GameObject* gameObject);
	virtual ~Component();
};