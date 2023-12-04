#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "fmt/format.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector.h"

#include <iostream>

const float SCREEN_WIDTH = 640;
const float SCREEN_HEIGHT = 480;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
InputManager* gInputManager;
GameObject* gTestGameObject;

void MoveDot(Vector2 moveInput)
{
	float moveSpeed = 2.0f;
	moveInput.Normalize();

	Vector2 moveVector = moveInput * moveSpeed;
	moveVector = Vector2::WorldToSDL(moveVector);
	gTestGameObject->transform.Translate(moveVector);

	if (Vector2::Magnitude(moveInput) == 0) return;
	Vector2 lookDirection = Vector2::Lerp(gTestGameObject->transform.up, moveInput, 0.1f);

	gTestGameObject->transform.LookAt(lookDirection);

	/*if (moveInput.x < 0) 
	{
		gTestGameObject->textureRenderer.flip = SDL_FLIP_VERTICAL;
	}
	else if(moveInput.x > 0)
	{
		gTestGameObject->textureRenderer.flip = SDL_FLIP_NONE;
	}*/
}


void RotateDot(double value)
{
	gTestGameObject->transform.Rotate(value);
}

bool Init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	gInputManager = InputManager::GetInstance();
	return success;
}

bool LoadMedia()
{
	//Loading success flag
	bool success = true;

	gTestGameObject = new GameObject(gRenderer, "Assets/bmp/dot.bmp", Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	return success;
}

void ProgramUpdate()
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			gInputManager->UpdateInputManager(e);
		}

		MoveDot(gInputManager->GetMoveInput());

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Update screen
		gTestGameObject->textureRenderer.Render(gTestGameObject->transform.position, gTestGameObject->transform.rotation);
		SDL_RenderPresent(gRenderer);
	}
}

void Close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Destroy GameObjects
	delete gTestGameObject;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!LoadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			ProgramUpdate();
		}
	}

	//Free resources and close SDL
	Close();

	return 0;
}