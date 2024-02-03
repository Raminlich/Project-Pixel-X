#include "GameObject.h"
#include "Transform.h"

GameObject::GameObject(const char* name, SDL_Renderer* sdlRenderer, Vector2 initialPosition, float initialRotation, Transform* parentTransform)
	:name(name)
{
	transform = new Transform(this, initialPosition, initialRotation ,parentTransform);
	//textureRenderer = new TextureRenderer(this , sdlRenderer, texturePath);
}

GameObject::~GameObject()
{
	std::cout << name << " Destroyed" << std::endl;

	//delete transform;
	//delete textureRenderer;

	//transform = nullptr;
	//textureRenderer = nullptr;
}

void GameObject::AddComponent(Component* component)
{
	components.emplace_back(component);
}

void GameObject::Update()
{
	for (Component* c : components)
	{
		c->Update();
	}
}
