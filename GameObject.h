#pragma once
#include "TextureRenderer.h"
#include "Transform.h"
#include "Vector.h"
#include <iostream>

class GameObject
{
public:
	Transform* transform;
	TextureRenderer* textureRenderer;

	GameObject(SDL_Renderer* sdlRenderer, std::string texturePath, Vector2 initialPosition, Transform* parentTransform);
	virtual ~GameObject();
};