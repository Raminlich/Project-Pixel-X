#pragma once
#include "SDL2/SDL.h"
#include "Vector.h"
#include <iostream>

class KeyBoardInput
{
private:
	SDL_KeyCode mKeyCode = SDLK_UNKNOWN;
	bool mIsDown = false;
public:
	KeyBoardInput(SDL_KeyCode keyCode);
	~KeyBoardInput();

	//For Handling isDown
	void HandleInput(const SDL_Event& e);

	//Returns is key Down or not
	bool GetIsDown();
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
	MoveInputHandler mMoveInput;
public:
	InputManager();
	~InputManager();

	void UpdateInputManager(const SDL_Event& e);
};