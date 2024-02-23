#pragma once

class GameObject;

class Component
{
public:
	GameObject* gameObject;

	Component(GameObject* gameObject);

	virtual void Update() = 0;
};

/*
Transform -> Done
TextureRenderer -> Done
Animation Data -> SpriteAnimator -> TextureRenderer (Ramin)
Collision (LazyFoo) (Nima)
Destroy ObjectManager (Nima)
Delete All Components At The End (Ramin)
R&D Timing in Game Engines (Ramin & Nima)
*/