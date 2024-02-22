#include "GameContext.h"
#include "iostream"
#include "Pyromancer.h"
#include "EventAction.h"

Pyromancer* pyromancer;
EventAction<void> testAction;
EventAction<int, int> testActionInt;

void Test(int x, int y) 
{
	std::cout << "test int " << x << " " << y;
}

GameContext::GameContext()
{
	std::cout << "Context Started..."<<std::endl;
	pyromancer = new Pyromancer();
	testAction += []()
		{
			std::cout << "test"<<std::endl;
		};
	testActionInt += Test;
	testAction.Invoke();
	testActionInt.Invoke(5, 6);

	testActionInt.RemoveAllActions();
	testActionInt.Invoke(5, 6);
}

GameContext::~GameContext()
{
	delete pyromancer;
	std::cout << "Context Ended..." << std::endl;

}
