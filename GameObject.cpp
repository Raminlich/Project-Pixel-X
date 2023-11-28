#include "GameObject.h"

void GameObject::InitTexture(std::string path)
{
	mTextureRenderer.LoadFromFile(path);
	mTextureRenderer.Render(mPosition);
}

GameObject::GameObject(SDL_Renderer* sdlRenderer,std::string texturePath, Vector2 initialPosition)
	:mTextureRenderer(sdlRenderer), mPosition(initialPosition)
{
	InitTexture(texturePath);
}

GameObject::~GameObject()
{

}

TextureRenderer GameObject::GetTextureRenderer()
{
	return mTextureRenderer;
}

void GameObject::Render()
{
	mTextureRenderer.Render(mPosition);
}

void GameObject::Move(Vector2 moveInput)
{
	Vector2 moveVector = Vector2(moveInput.x,-moveInput.y) * mMoveSpeed;
	mPosition = mPosition + (moveVector);
}