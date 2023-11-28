#pragma once
#include "TextureRenderer.h"
#include "Vector.h"

#include <iostream>

class MoveAble
{
public:
	//Moving gameobject with a move vector
	virtual void Move(Vector2 moveVector) = 0;
};

class GameObject : public MoveAble
{
private:
	//Texture renderer for gameobject to render
	TextureRenderer mTextureRenderer;

	//Position of gameobject
	Vector2 mPosition;
	float mMoveSpeed = 2.0f;

public:
	void InitTexture(std::string path);

	GameObject(SDL_Renderer* sdlRenderer,std::string texturePath,Vector2 initialPosition);
	virtual ~GameObject();

	void Move(Vector2 moveInput) override;

	void Render();

	//returns gameobject texture renderer
	TextureRenderer GetTextureRenderer();
};
