#include "GameContext.h"
#include "iostream"
#include "Pyromancer.h"
#include "PhysicsHandler.h"
#include "EventAction.h"

Pyromancer* pyromancer;
EventAction<void> testAction;
EventAction<int, int> testActionInt;

PhysicsHandler* groundPhysicsHandler;
PhysicsHandler* boxPhysicsHandler;

void Test(int x, int y) 
{
	std::cout << "test int " << x << " " << y;
}

GameContext::GameContext()
{
	/*std::cout << "Context Started..."<<std::endl;
	pyromancer = new Pyromancer();
	testAction += []()
		{
			std::cout << "test"<<std::endl;
		};
	testActionInt += Test;
	testAction.Invoke();
	testActionInt.Invoke(5, 6);

	testActionInt.RemoveAllActions();
	testActionInt.Invoke(5, 6);*/

	GameObject* groundGO = ObjectManager::GetInstance()->CreateGameObject("Ground", Vector2(0,0), 0.0f);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(50.0f, 10.0f);
	b2FixtureDef groundFixtureDef;
	groundFixtureDef.shape = &groundShape;
	groundPhysicsHandler = new PhysicsHandler(groundGO, groundBodyDef, groundFixtureDef);
	groundGO->AddComponent(groundPhysicsHandler);

	GameObject* boxGO = ObjectManager::GetInstance()->CreateGameObject("Box", Vector2(0, 0), 0.0f);
	b2BodyDef boxBodyDef;
	boxBodyDef.type = b2_dynamicBody;
	boxBodyDef.position.Set(0.0f, 4.0f);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(1.0f, 1.0f);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1.0f;
	boxFixtureDef.friction = 0.3f;
	boxPhysicsHandler = new PhysicsHandler(boxGO, boxBodyDef, boxFixtureDef);
	boxGO->AddComponent(boxPhysicsHandler);
}

GameContext::~GameContext()
{
	//delete pyromancer;
	std::cout << "Context Ended..." << std::endl;

}

void GameContext::Update()
{
	std::cout << boxPhysicsHandler->GetPosition() << std::endl;
}
