#include "Pyromancer.h"

GameObject* gTestGameObject1;
GameObject* gAnimatedObject;
SDL_Texture* animatedSprite;
SpriteAnimator* animator;
TextureRenderer* textureRenderer;

Pyromancer::Pyromancer()
{
	LoadMedia();
}

void MoveDot2(Vector2 moveInput)
{
	if (moveInput.y == 0) return;
	float moveSpeed = 2.0f;
	float rotationSpeed = 2.0f;

	Vector2 moveVector = gTestGameObject1->transform->GetUp() * moveInput.y * moveSpeed;
	moveVector = Vector2::WorldToSDL(moveVector);
	gTestGameObject1->transform->Translate(moveVector);

	gTestGameObject1->transform->Rotate(moveInput.x * rotationSpeed);
}

bool Pyromancer::LoadMedia()
{
	bool success = true;

	gTestGameObject1 = ObjectManager::GetInstance()->CreateGameObject("G01", Vector2(0, 0), 0.0f);
	gTestGameObject1->transform->SetScale(Vector2(1.5f, 1.5f));

	textureRenderer = new TextureRenderer(gTestGameObject1, "Assets/Pyromancer_Idle.png");
	animator = new SpriteAnimator(gTestGameObject1, textureRenderer);
	animator->SetFrames(8, 150, 0, 150, 150);

	//for GetComponent test
	auto test = gTestGameObject1->GetComponent<SpriteAnimator>();
	if (test != nullptr) 
	{
		std::cout << "Success" << std::endl;
	}

	return success;
}

