#pragma once
#include "Transform.h"

class ObjectManager 
{
private:
	ObjectManager();
	~ObjectManager();

	static ObjectManager* objectManager_;
public:
	ObjectManager(ObjectManager& other) = delete;
	void operator = (const ObjectManager& other) = delete;

	static ObjectManager* GetInstance();
	static void ResetInstance();
};
