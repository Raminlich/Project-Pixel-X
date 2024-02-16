#include "GameContext.h"
#include "iostream"
#include "Pyromancer.h"

GameContext::GameContext()
{
	std::cout << "Context Started..."<<std::endl;
	new Pyromancer();
}
