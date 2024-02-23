#include "PhysicsManager.h"
#include "Vector.h"

PhysicsManager* PhysicsManager::physicsManager_ = nullptr;

PhysicsManager::PhysicsManager()
{
	Vector2 gravity(0,-9.81f);
	SetGravity(gravity);
	mWorld = new b2World(this->gravity);
}

PhysicsManager::~PhysicsManager()
{
	delete mWorld;
	mWorld = nullptr;
}

PhysicsManager* PhysicsManager::GetInstance()
{
	if (physicsManager_ == nullptr) 
	{
		physicsManager_ = new PhysicsManager();
	}

	return physicsManager_;
}

void PhysicsManager::ResetInstance()
{
	delete physicsManager_;
	physicsManager_ = nullptr;
}

b2World* PhysicsManager::GetWorld()
{
	return mWorld;
}


void PhysicsManager::SetGravity(Vector2 gravity)
{
	this->gravity = b2Vec2(gravity.x, gravity.y);
	if (mWorld == nullptr) return;
	mWorld->SetGravity(this->gravity);
}