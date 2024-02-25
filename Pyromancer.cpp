#include "Pyromancer.h"
#include "PhysicsHandler.h"
#include "PhysicsManager.h"

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
	gTestGameObject1->AddComponent(textureRenderer);
	gTestGameObject1->AddComponent(animator);

	int MET2PIX = PhysicsManager::GetInstance()->MET2PIX;
	float RAD2DEG = PhysicsManager::GetInstance()->RAD2DEG;

	b2BodyDef boxBodyDef;
	boxBodyDef.type = b2_dynamicBody;
	boxBodyDef.position.Set(320/MET2PIX, 0.0f/MET2PIX);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1.0f/MET2PIX, 1.0f/MET2PIX);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1.0f;
	boxFixtureDef.friction = 0.3f;
	auto boxPhysicsHandler = new PhysicsHandler(gTestGameObject1, boxBodyDef, boxFixtureDef);
	gTestGameObject1->AddComponent(boxPhysicsHandler);

	GameObject* groundGO = ObjectManager::GetInstance()->CreateGameObject("Ground", Vector2(0, 0), 0.0f);
	b2BodyDef groundBodyDef;
	groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set(0.0f, 480.0f/MET2PIX);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(50.0f / MET2PIX, 10.0f / MET2PIX);
	b2FixtureDef groundFixtureDef;
	groundFixtureDef.shape = &groundShape;
	auto groundPhysicsHandler = new PhysicsHandler(groundGO, groundBodyDef, groundFixtureDef);
	groundGO->AddComponent(groundPhysicsHandler);

	//for GetComponent test
	auto test = gTestGameObject1->GetComponent<SpriteAnimator>();
	if (test != nullptr) 
	{
		std::cout << "Success" << std::endl;
	}

	return success;
}

