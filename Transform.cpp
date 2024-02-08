#include "Transform.h"
#include "GameObject.h"

#include <cmath>
#include <algorithm>


Transform::Transform(GameObject* gameObject, const Vector2& initialPosition, float initialRotation,Transform* parentTransform)
	: mGlobalPosition(initialPosition), mGlobalRotation(initialRotation), mParent(parentTransform)
{
	if (mParent != nullptr)
	{
		mParent->mChildrenTransform.emplace_back(this);
	}

	HandleDirection();
}

Transform::~Transform()
{

}

void Transform::Update()
{

}

const Transform* const Transform::GetParent()
{
	return mParent;
}

Vector2 Transform::GetPosition()
{
	return mGlobalPosition;
}

Vector2 Transform::GetLocalPosition()
{
	if (mParent == nullptr) 
	{
		return mGlobalPosition;
	}
	else
	{
		return mGlobalPosition - mParent->GetPosition();
	}
}

float Transform::GetRotation()
{
	return mGlobalRotation;
}

float Transform::GetLocalRotation()
{
	if (mParent == nullptr)
	{
		return mGlobalRotation;
	}
	else
	{
		return mGlobalRotation - mParent->GetRotation();
	}
}

Vector2 Transform::GetScale()
{
	return mGlobalScale;
}

Vector2 Transform::GetLocalScale()
{
	if (mParent == nullptr)
	{
		return mGlobalScale;
	}
	else
	{
		Vector2 parentScale = mParent->GetScale();
		return Vector2(mGlobalScale.x / parentScale.x, mGlobalScale.y / parentScale.y);
	}
}

Vector2 Transform::GetUp()
{
	return mUp;
}

Vector2 Transform::GetRight()
{
	return mRight;
}

void Transform::SetPosition(const Vector2& position)
{
	for (Transform* childTransform : mChildrenTransform)
	{
		childTransform->SetPosition(childTransform->GetLocalPosition() + position);
	}
	mGlobalPosition = position;
}

void Transform::SetLocalPosition(const Vector2& position)
{
	if (mParent == nullptr) 
	{
		SetPosition(position);
	}
	else
	{
		SetPosition(mParent->GetPosition() + position);
	}
}

void Transform::SetRotation(float rotation)
{
	for (Transform* childTransform : mChildrenTransform)
	{
		childTransform->SetRotation(childTransform->GetLocalRotation() + rotation);
	}
	mGlobalRotation = rotation;

	HandleDirection();
}

void Transform::SetLocalRotation(float rotation)
{
	if (mParent == nullptr)
	{
		SetRotation(rotation);
	}
	else
	{
		SetRotation(mParent->GetRotation() + rotation);
	}
}

void Transform::SetScale(const Vector2& scale)
{
	for (Transform* childTransform : mChildrenTransform)
	{
		Vector2 childScale = childTransform->GetLocalScale();
		childTransform->SetScale(Vector2(childScale.x * scale.x, childScale.y * scale.y));
	}
	mGlobalScale = scale;
}

void Transform::SetLocalScale(const Vector2& scale)
{
	if (mParent == nullptr)
	{
		SetScale(scale);
	}
	else
	{
		Vector2 parentScale = mParent->GetScale();
		SetScale(Vector2(parentScale.x * scale.x, parentScale.y * scale.y));
	}
}

void Transform::SetUp(const Vector2& up)
{
	float angle = Vector2::FindAngle(mUp, up);
	Rotate(angle);
}

void Transform::SetRight(const Vector2& right)
{
	float angle = Vector2::FindAngle(mRight, right);
	Rotate(angle);
}

void Transform::SetParent(Transform* newParentTransform)
{
	if (mParent != nullptr)
	{
		mParent->mChildrenTransform.erase(std::remove(mParent->mChildrenTransform.begin(), mParent->mChildrenTransform.end(), this), mParent->mChildrenTransform.end());
	}

	mParent = newParentTransform;
	if (mParent != nullptr)
	{
		mParent->mChildrenTransform.emplace_back(this);
	}
}

const std::vector<Transform*>& Transform::GetChilderen()
{
	return mChildrenTransform;
}

void Transform::Translate(const Vector2& translateVector)
{
	Vector2 newPosition = mGlobalPosition + translateVector;
	SetPosition(newPosition);
}

void Transform::Rotate(const float& rotationValue)
{
	float newRotation = mGlobalRotation + rotationValue;
	SetRotation(newRotation);
}

void Transform::LookAt(Vector2 lookDirection)
{
	float angle = Vector2::FindAngle(Vector2::UP, lookDirection);
	SetRotation(angle);
}

void Transform::HandleDirection()
{
	mUp = Vector2::UP;
	mUp.Rotate(mGlobalRotation);

	mRight = Vector2::RIGHT;
	mRight.Rotate(mGlobalRotation);
}
