#pragma once
#include <functional>
#include <vector>

template<typename... Args>
class EventAction
{
public:
	using ActionType = std::function<void(Args...)>;

	void operator+=(ActionType action);

	void Add(ActionType action);

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

	void Add(ActionType action);

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
inline void EventAction<Args...>::Add(ActionType action)
{
	actions.push_back(action);
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

inline void EventAction<void>::Add(ActionType action)
{
	actions.push_back(action);
}

inline void EventAction<void>::Invoke()
{
	for (const auto& action : actions)
	{
		action();
	}
}
