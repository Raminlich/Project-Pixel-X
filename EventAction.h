#pragma once
#include <functional>
#include <vector>

template<typename... Args>
class EventAction
{
public:
	using ActionType = std::function<void(Args...)>;

	void operator+=(ActionType action);

	void operator-=(ActionType action);

	void Add(ActionType action);

	void Remove(ActionType action);

	void RemoveAllActions();

	void Invoke(Args... args);

private:
	std::vector<ActionType> actions;
};

template<>
class EventAction<void>
{
public:
	using ActionType = std::function<void()>;

	void operator+=(ActionType action);

	void operator-=(ActionType action);

	void Add(ActionType action);

	void Remove(ActionType action);

	void RemoveAllActions();

	void Invoke();

private:
	std::vector<ActionType> actions;
};


//Definition

template<typename ...Args>
inline void EventAction<Args...>::operator+=(ActionType action)
{
	Add(action);
}

template<typename ...Args>
inline void EventAction<Args...>::operator-=(ActionType action)
{
	Remove(action);
}

template<typename ...Args>
inline void EventAction<Args...>::Add(ActionType action)
{
	actions.push_back(action);
}

template<typename ...Args>
inline void EventAction<Args...>::Remove(ActionType action)
{
	auto it = std::find_if(actions.begin(), actions.end(), [action](const ActionType& a)
		{
			return a.target_type() == action.target_type() && a.target<void>() == action.target<void>();
		});
	if (it != actions.end())
	{
		actions.erase(it);
		std::cout << "Action found removing it..." << std::endl;
	}
	else
	{
		std::cout << "Action not found..." << std::endl;
	}
}

template<typename ...Args>
inline void EventAction<Args...>::RemoveAllActions()
{
	actions.clear();
}

template<typename ...Args>
inline void EventAction<Args...>::Invoke(Args ...args)
{
	for (const auto& action : actions)
	{
		action(args...);
	}
}

inline void EventAction<void>::operator+=(ActionType action)
{
	Add(action);
}

inline void EventAction<void>::operator-=(ActionType action)
{
	Remove(action);
}

inline void EventAction<void>::Add(ActionType action)
{
	actions.push_back(action);
}

inline void EventAction<void>::Remove(ActionType action)
{
	//auto it = std::find(actions.begin(), actions.end(), action);
	auto it = std::find_if(actions.begin(), actions.end(), [action](const ActionType& a)
		{
			return a.target_type() == action.target_type() && a.target<void>() == action.target<void>();
		});
	if (it != actions.end())
	{
		actions.erase(it);
		std::cout << "Action found removing it..." << std::endl;
	}
	else
	{
		std::cout << "Action not found..." << std::endl;
	}
}

inline void EventAction<void>::RemoveAllActions()
{
	actions.clear();
}

inline void EventAction<void>::Invoke()
{
	for (const auto& action : actions)
	{
		action();
	}
}
