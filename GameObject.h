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
	//TextureRenderer* textureRenderer;

	GameObject(const char* name, SDL_Renderer* sdlRenderer, Vector2 initialPosition, float initialRotation, Transform* parentTransform);
	virtual ~GameObject();
	void AddComponent(Component* component);
	template <typename T>
	T* GetComponent() const;
private :
	std::vector<Component*> components;

	// Inherited via Component
	void Update();
};

template<typename T>
inline T* GameObject::GetComponent() const
{
	return nullptr;
}
