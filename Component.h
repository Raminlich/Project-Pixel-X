#pragma once

class GameObject;

class Component
{
public:
	GameObject* mGameObject = nullptr;

	Component(GameObject* gameObject);
	virtual ~Component();
};