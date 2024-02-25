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
	std::cout << "Context Started..."<<std::endl;
	pyromancer = new Pyromancer();
}

GameContext::~GameContext()
{
	delete pyromancer;
	std::cout << "Context Ended..." << std::endl;

}

void GameContext::Update()
{

}
