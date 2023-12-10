#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* sdlRenderer,std::string texturePath, Vector2 initialPosition, Transform* parentTransform)
{
	transform = new Transform(this, initialPosition, parentTransform);
	textureRenderer = new TextureRenderer(this , sdlRenderer, texturePath);
}

GameObject::~GameObject()
{
	for(Transform* childTransform : transform->GetChilderen())
	{
		delete childTransform->mGameObject;
	}

	delete transform;
	delete textureRenderer;

	transform = nullptr;
	textureRenderer = nullptr;
}