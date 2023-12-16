#include "ObjectManager.h"
#include "Transform.h"
#include "GameObject.h"

#include <algorithm>


ObjectManager* ObjectManager::objectManager_ = nullptr;



ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	for (GameObject* gameObject : mGameObjects) 
	{
		DestroyAll();
	}
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

void ObjectManager::Update()
{
	for (GameObject* gameObject : mGameObjects) 
	{
		gameObject->Update();
	}
}

void ObjectManager::SetRenderer(SDL_Renderer* sdlRenderer)
{
	mSDLRenderer = sdlRenderer;
}

GameObject* ObjectManager::CreateGameObject(const char* name, const char* texturePath, Vector2 initialPosition, float initialRotation, Transform* parentTransform)
{
	if (mSDLRenderer == nullptr) 
	{
		std::cout << "SDL Renderer is not set in object manager" << std::endl;
		return nullptr;
	}

	GameObject* newGO = new GameObject(name,mSDLRenderer, texturePath, initialPosition, initialRotation, parentTransform);
	mGameObjects.emplace_back(newGO);
	return newGO;
}

void ObjectManager::DestroyAll()
{
	for (GameObject* gameObject : mGameObjects) 
	{
		delete gameObject;
		gameObject = nullptr;
	}

	mGameObjects.clear();
}

void ObjectManager::Destroy(GameObject* gameObject)
{
	//TODO: Destroy Children of given gameObject

	mGameObjects.erase(remove(mGameObjects.begin(), mGameObjects.end(), gameObject), mGameObjects.end());
	delete gameObject;
}
