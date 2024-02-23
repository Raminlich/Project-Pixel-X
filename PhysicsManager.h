#pragma once
#include "box2d/box2d.h"

class Vector2;

class PhysicsManager
{
private:
	PhysicsManager();
	~PhysicsManager();

	static PhysicsManager* physicsManager_;

	b2Vec2 gravity;
	b2World* mWorld = nullptr;
public:
	PhysicsManager(PhysicsManager& other) = delete;
	void operator = (const PhysicsManager& other) = delete;

	static PhysicsManager* GetInstance();
	static void ResetInstance();

	//Returns created world
	b2World* GetWorld();

	//Set world's gravity
	void SetGravity(Vector2 gravity);
};