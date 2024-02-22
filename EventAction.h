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



