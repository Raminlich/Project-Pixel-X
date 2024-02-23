#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject* gameObject)
	: gameObject(gameObject)
{
	gameObject->AddComponent(this);
}
