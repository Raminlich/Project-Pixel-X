#pragma once
#include "TextureRenderer.h"
#include "Vector.h"
#include <iostream>
#include <vector>

class Transform;

class GameObject
{
public:
	const char* name;

	Transform* transform;
	GameObject(const char* name, Vector2 initialPosition, float initialRotation, Transform* parentTransform);
	virtual ~GameObject();
	void AddComponent(Component* component);
	template <typename T>
	T* GetComponent() const;
	void Update();
private :
	std::vector<Component*> components;
};

template<typename T>
inline T* GameObject::GetComponent() const
{
	return nullptr;
}
