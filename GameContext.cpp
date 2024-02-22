#include "GameContext.h"
#include "iostream"
#include "Pyromancer.h"
#include "EventAction.h"

Pyromancer* pyromancer;
EventAction<void> testAction;

GameContext::GameContext()
{
	std::cout << "Context Started..."<<std::endl;
	pyromancer = new Pyromancer();
	testAction += []()
		{
			std::cout << "test";
		};
	testAction.Invoke();

}

GameContext::~GameContext()
{
	delete pyromancer;
	std::cout << "Context Ended..." << std::endl;

}
