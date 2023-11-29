#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* sdlRenderer,std::string texturePath, Vector2 initialPosition)
{
	transform = Transform(initialPosition);
	textureRenderer = TextureRenderer(sdlRenderer);

	textureRenderer.Init(texturePath, initialPosition);
}

GameObject::~GameObject()
{

}