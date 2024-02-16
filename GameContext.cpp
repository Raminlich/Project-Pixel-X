#include "GameContext.h"
#include "iostream"
#include "Pyromancer.h"

Pyromancer* pyromancer;

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
