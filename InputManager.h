#pragma once
#include "SDL2/SDL.h"
#include "Vector.h"

#include <iostream>

class KeyBoardInput
{
private:
	SDL_KeyCode mKeyCode = SDLK_UNKNOWN;
	bool mIsPressed = false;
public:
	KeyBoardInput(SDL_KeyCode keyCode);
	~KeyBoardInput();

	//For Handling is key pressed
	void HandleInput(const SDL_Event& e);

	//Returns is key Pressed or not
	bool GetIsPressed();
};

//For handling move Input
class MoveInputHandler
{
private:
	//Calculated move input based on inputs
	KeyBoardInput mUpKey = KeyBoardInput(SDLK_UP);
	KeyBoardInput mDownKey = KeyBoardInput(SDLK_DOWN);
	KeyBoardInput mRightKey = KeyBoardInput(SDLK_RIGHT);
	KeyBoardInput mLeftKey = KeyBoardInput(SDLK_LEFT);
	Vector2 mMoveInput;

public:
	MoveInputHandler();
	~MoveInputHandler();

	//For updating keyboardInputs
	void UpdateMoveInput(const SDL_Event& e);
	//For calculating move input based on SDL_Events
	void CalculateMoveInput();
	Vector2 GetMoveInput();
};

class InputManager
{
private:
	MoveInputHandler mMoveInputHandler;
public:
	InputManager();
	~InputManager();

	void UpdateInputManager(const SDL_Event& e);
	Vector2 GetMoveInput();
};