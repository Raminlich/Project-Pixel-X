#include "PhysicsHandler.h"
#include "PhysicsManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector.h"

void PhysicsHandler::UpdateTransform()
{
	gameObject->transform->SetPosition(GetPosition());
	gameObject->transform->SetRotation(GetRotation());
}

PhysicsHandler::PhysicsHandler(GameObject* gameObject, b2BodyDef bodyDef, b2FixtureDef fixtureDef)
	: Component(gameObject), 
	mWorld(PhysicsManager::GetInstance()->GetWorld()),
	MET2PIX(PhysicsManager::GetInstance()->MET2PIX),
	RAD2DEG(PhysicsManager::GetInstance()->RAD2DEG)
{
	Init(bodyDef, fixtureDef);
}

Vector2 PhysicsHandler::GetPosition()
{
	b2Vec2 position = mBody->GetPosition();
	return Vector2(position.x * MET2PIX, position.y * MET2PIX);
}

void PhysicsHandler::SetPosition(Vector2 newPosition)
{
	b2Vec2 newBodyPosition(newPosition.x/MET2PIX, newPosition.y/MET2PIX);
	mBody->SetTransform(newBodyPosition, mBody->GetAngle());
	UpdateTransform();
}

float PhysicsHandler::GetRotation()
{
	return mBody->GetAngle() * RAD2DEG;
}

void PhysicsHandler::SetRotation(float newRotation)
{
	mBody->SetTransform(mBody->GetPosition(), newRotation/RAD2DEG);
	UpdateTransform();
}

void PhysicsHandler::Update()
{
	UpdateTransform();
}

void PhysicsHandler::Init(b2BodyDef bodyDef, b2FixtureDef fixtureDef)
{
	mBody = mWorld->CreateBody(&bodyDef);
	mBody->CreateFixture(&fixtureDef);
}

PhysicsHandler::~PhysicsHandler()
{

}