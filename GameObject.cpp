#include "GameObject.h"
#include "Transform.h"

GameObject::GameObject(const char* name, SDL_Renderer* sdlRenderer, const char* texturePath, Vector2 initialPosition, float initialRotation, Transform* parentTransform)
	:name(name)
{
	transform = new Transform(this, initialPosition, initialRotation ,parentTransform);
	textureRenderer = new TextureRenderer(this , sdlRenderer, texturePath);
}

GameObject::~GameObject()
{
	std::cout << name << " Destroyed" << std::endl;

	delete transform;
	delete textureRenderer;

	transform = nullptr;
	textureRenderer = nullptr;
}

void GameObject::Update() 
{
	transform->Update();
	textureRenderer->Update();
}