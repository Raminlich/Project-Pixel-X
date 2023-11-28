#pragma once
#include "TextureRenderer.h"
#include "Vector.h"
#include <iostream>

class GameObject
{
public:
	TextureRenderer mTextureRenderer;
	Vector2 mPosition;
	void InitTexture(std::string path);
	GameObject(SDL_Renderer* sdlRenderer,std::string texturePath,Vector2 initialPosition);
	virtual ~GameObject();
	void Render();
	TextureRenderer GetTextureRenderer();
};
