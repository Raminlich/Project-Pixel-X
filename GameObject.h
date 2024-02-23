#pragma once
#include "TextureRenderer.h"
#include "Vector.h"
#include <iostream>
#include <vector>

class Component;
class Transform;

class GameObject
{
public:
	const char* name;

	Transform* transform;
	GameObject(const char* name, Vector2 initialPosition, float initialRotation, Transform* parentTransform);
	virtual ~GameObject();
	template <typename T>
	T* GetComponent() const;
	void Update();
private :
	void AddComponent(Component* component);
	std::vector<Component*> components;
	friend class Component;
};

template<typename T>
inline T* GameObject::GetComponent() const
{
	for (Component* component : components) 
	{
		if (typeid(*component) == typeid(T)) 
		{
			return (T*)component;
		}
	}
	return nullptr;
}
