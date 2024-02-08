#pragma once
#include "SDL2/SDL.h"
#include "Vector.h"

#include <vector>

class GameObject;
class Transform;

class ObjectManager 
{
private:
	ObjectManager();
	~ObjectManager();

	static ObjectManager* objectManager_;

	std::vector<GameObject*> mGameObjects;

	SDL_Renderer* mSDLRenderer;
public:
	ObjectManager(ObjectManager& other) = delete;
	void operator = (const ObjectManager& other) = delete;

	static ObjectManager* GetInstance();
	static void ResetInstance();

	void Update();

	void SetRenderer(SDL_Renderer* sdlRenderer);
	GameObject* CreateGameObject(const char* name, const char* texturePath, Vector2 initialPosition, float initialRotation, Transform* parentTransform); // Creates and returns new game object
	void AddGameObject(GameObject* gameObject);
	void DestroyAll(); //Destroys all gameobjects
	void Destroy(GameObject* gameObject); //Destroys given gameobject
};
