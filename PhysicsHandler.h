#pragma once
#include "Component.h"
#include "box2d/box2d.h"

class GameObject;
class Vector2;

class PhysicsHandler : public Component
{
private:
	b2World* mWorld;
	b2Body* mBody;
	
	void Init(b2BodyDef bodyDef, b2FixtureDef fixtureDef);
public:
	PhysicsHandler(GameObject* gameObject, b2BodyDef bodyDef, b2FixtureDef fixtureDef);

	Vector2 GetPosition();

	float GetRotation();

	void Update();

	~PhysicsHandler();
};