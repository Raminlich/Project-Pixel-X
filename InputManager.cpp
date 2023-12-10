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
	if (e.key.keysym.sym != mKeyCode) return;

	switch (e.key.state)
	{
	case SDL_PRESSED:
		mIsPressed = true;
		break;

	case SDL_RELEASED:
		mIsPressed = false;
		break;
	}
}

bool KeyBoardInput::GetIsPressed()
{
	return mIsPressed;
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
	bool up = mUpKey.GetIsPressed();
	bool down = mDownKey.GetIsPressed();
	bool right = mRightKey.GetIsPressed();
	bool left = mLeftKey.GetIsPressed();


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

InputManager* InputManager::inputManager_ = nullptr;

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

Vector2 InputManager::GetMoveInput()
{
	return mMoveInputHandler.GetMoveInput();
}

InputManager* InputManager::GetInstance()
{
	if(inputManager_ == nullptr)
	{
		inputManager_ = new InputManager();
	}

	return inputManager_;
}

void InputManager::ResetInstance()
{
	delete inputManager_;
	inputManager_ = nullptr;
}

void InputManager::UpdateInputManager(const SDL_Event& e)
{
	mMoveInputHandler.UpdateMoveInput(e);
}
