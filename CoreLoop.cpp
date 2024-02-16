#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "fmt/format.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector.h"
#include "SpriteAnimator.h"
#include "map"
#include <iostream>
#include "GameContext.h"


const float SCREEN_WIDTH = 640;
const float SCREEN_HEIGHT = 480;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

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

	ObjectManager::GetInstance()->SetRenderer(gRenderer);
	GameContext* context = new GameContext();
	return success;
}

void Close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	//Handling singletons
	InputManager::ResetInstance();
	ObjectManager::ResetInstance();
	ResourceManager::ResetInstance();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void ProgramUpdate()
{
	bool quit = false;
	Uint32 startTime = 0;
	int countedFrames = 0;
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

			InputManager::GetInstance()->UpdateInputManager(e);
		}

		float avgFPS = countedFrames / (SDL_GetTicks64() / 1000.0f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}
		std::cout << avgFPS << std::endl;
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gRenderer);

		ObjectManager::GetInstance()->Update();

		SDL_RenderPresent(gRenderer);
		++countedFrames;
	}
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
		ProgramUpdate();
	}

	//Free resources and close SDL
	Close();

	return 0;
}