#include "EventAction.h"

template<typename ...Args>
void EventAction<Args...>::operator+=(ActionType action)
{
	Add(action);
}

template<typename ...Args>
void EventAction<Args...>::Add(ActionType action)
{
	actions.push_back(action);
}

template<typename ...Args>
void EventAction<Args...>::Invoke(Args ...args)
{
	for (const auto& action : actions)
	{
		action(args...);
	}
}

void EventAction<void>::operator+=(ActionType action)
{
	Add(action);
}

 void EventAction<void>::Add(ActionType action)
{
	actions.push_back(action);
}

void EventAction<void>::Invoke()
{
	for (const auto& action : actions)
	{
		action();
	}
}
