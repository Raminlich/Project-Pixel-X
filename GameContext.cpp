#include "GameContext.h"
#include "iostream"
#include "Pyromancer.h"
#include "EventAction.h"

Pyromancer* pyromancer;
EventAction<void> testAction;
EventAction<int, int> testActionInt;

GameContext::GameContext()
{
	std::cout << "Context Started..."<<std::endl;
	pyromancer = new Pyromancer();
	testAction += []()
		{
			std::cout << "test"<<std::endl;
		};
	testActionInt += ([](int x, int y)
		{
			std::cout << "test int " <<x << " " << y;
		});
	testAction.Invoke();
	testActionInt.Invoke(5, 6);

}

GameContext::~GameContext()
{
	delete pyromancer;
	std::cout << "Context Ended..." << std::endl;

}
