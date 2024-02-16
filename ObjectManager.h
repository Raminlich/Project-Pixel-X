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
	SDL_Renderer* GetRenderer();
	GameObject* CreateGameObject(const char* name, Vector2 initialPosition, float initialRotation, Transform* parentTransform = nullptr); // Creates and returns new game object
	void DestroyAll(); //Destroys all gameobjects
	void Destroy(GameObject* gameObject); //Destroys given gameobject
};
