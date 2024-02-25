#pragma once
#include "box2d/box2d.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Vector2;

class PhysicsManager
{
private:
	PhysicsManager();
	~PhysicsManager();

	static PhysicsManager* physicsManager_;

	b2Vec2 gravity;
	b2World* mWorld = nullptr;

	const float timeStep = 1.0f / 60.0f; //World simulation parameter
	const int32 velocityIterations = 6; //World simulation parameter
	const int32 positionIterations = 2; //World simulation parameter

public:
	PhysicsManager(PhysicsManager& other) = delete;
	void operator = (const PhysicsManager& other) = delete;

	static PhysicsManager* GetInstance();
	static void ResetInstance();

	//For converting meter unit to pixel unit and vice versa
	const int MET2PIX = 80;
	//For converting radian unit to degree and vice versa
	const float RAD2DEG = 180.0f / M_PI;

	//Returns created world
	b2World* GetWorld();

	//Set world's gravity
	void SetGravity(Vector2 gravity);

	//Simulates the world (Should be called in core loop update)
	void Update();
};