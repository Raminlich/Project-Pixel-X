#include "ObjectManager.h"

ObjectManager* ObjectManager::objectManager_ = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	
}

ObjectManager* ObjectManager::GetInstance()
{
	if (objectManager_ == nullptr) 
	{
		objectManager_ = new ObjectManager();
	}

	return objectManager_;
}

void ObjectManager::ResetInstance()
{
	delete objectManager_;
	objectManager_ = nullptr;
}