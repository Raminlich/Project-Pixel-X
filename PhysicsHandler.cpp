#include "PhysicsHandler.h"
#include "PhysicsManager.h"
#include "Vector.h"

PhysicsHandler::PhysicsHandler(GameObject* gameObject, b2BodyDef bodyDef, b2FixtureDef fixtureDef)
	: Component(gameObject), mWorld(PhysicsManager::GetInstance()->GetWorld())
{
	Init(bodyDef, fixtureDef);
}

Vector2 PhysicsHandler::GetPosition()
{
	//TODO : need to convert box2d units to sdl2 units
	b2Vec2 position = mBody->GetPosition();
	return Vector2(position.x , position.y);
}

float PhysicsHandler::GetRotation()
{
	//TODO : need to convert radian to degree
	return mBody->GetAngle();
}

void PhysicsHandler::Init(b2BodyDef bodyDef, b2FixtureDef fixtureDef)
{
	mBody = mWorld->CreateBody(&bodyDef);
	mBody->CreateFixture(&fixtureDef);
}

PhysicsHandler::~PhysicsHandler()
{

}