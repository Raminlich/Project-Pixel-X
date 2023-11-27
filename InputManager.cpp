#include "InputManager.h"

#pragma region Inputs

KeyBoardInput::KeyBoardInput(SDL_KeyCode keyCode)
	:mKeyCode(keyCode)
{
	
}

KeyBoardInput::~KeyBoardInput()
{

}

void KeyBoardInput::HandleInput(const SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		if (e.key.keysym.sym != mKeyCode) break;
		mIsDown = true;
		break;

	case SDL_KEYUP:
		if (e.key.keysym.sym != mKeyCode) break;
		mIsDown = false;
		break;
	}
}

bool KeyBoardInput::GetIsDown()
{
	return mIsDown;
}

MoveInputHandler::MoveInputHandler()
{
}

MoveInputHandler::~MoveInputHandler()
{
}

void MoveInputHandler::UpdateMoveInput(const SDL_Event& e)
{
	mUpKey.HandleInput(e);
	mDownKey.HandleInput(e);
	mRightKey.HandleInput(e);
	mLeftKey.HandleInput(e);
}

void MoveInputHandler::CalculateMoveInput()
{ 
	bool up = mUpKey.GetIsDown();
	bool down = mDownKey.GetIsDown();
	bool right = mRightKey.GetIsDown();
	bool left = mLeftKey.GetIsDown();


	if (up && down) 
	{
		mMoveInput.y = 0;
	}
	else if (up)
	{
		mMoveInput.y = 1;
	}
	else if(down)
	{
		mMoveInput.y = -1;
	}
	else
	{
		mMoveInput.y = 0;
	}

	if (right && left)
	{
		mMoveInput.x = 0;
	}
	else if (right)
	{
		mMoveInput.x = 1;
	}
	else if (left)
	{
		mMoveInput.x = -1;
	}
	else
	{
		mMoveInput.x = 0;
	}
}

Vector2 MoveInputHandler::GetMoveInput()
{
	CalculateMoveInput();
	return mMoveInput;
}

#pragma endregion

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::UpdateInputManager(const SDL_Event& e)
{
	mMoveInput.UpdateMoveInput(e);
	std::cout << "Input : " << mMoveInput.GetMoveInput().x << ", " << mMoveInput.GetMoveInput().y << std::endl;
}
