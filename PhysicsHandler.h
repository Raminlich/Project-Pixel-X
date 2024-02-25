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

	const int MET2PIX;
	float RAD2DEG;
	
	void Init(b2BodyDef bodyDef, b2FixtureDef fixtureDef);
	
	//For updating transform component based on physics
	void UpdateTransform();
public:
	PhysicsHandler(GameObject* gameObject, b2BodyDef bodyDef, b2FixtureDef fixtureDef);

	//Get position of body in pixel units
	Vector2 GetPosition();

	//Set position of body based on input (in pixel)
	void SetPosition(Vector2 newPosition);

	//Get rotation of body in degree units
	float GetRotation();

	//Set rotation of body based on input (in degree)
	void SetRotation(float newRotation);

	void Update();

	~PhysicsHandler();
};