#pragma once
#include "TextureRenderer.h"
#include "Vector.h"
#include <iostream>

class Transform;

class GameObject
{
public:
	const char* name;

	Transform* transform;
	TextureRenderer* textureRenderer;

	GameObject(const char* name, SDL_Renderer* sdlRenderer, const char* texturePath, Vector2 initialPosition, float initialRotation, Transform* parentTransform);
	virtual ~GameObject();

	void Update();
};