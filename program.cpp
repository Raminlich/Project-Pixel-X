#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "fmt/format.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector.h"

#include <iostream>

const float SCREEN_WIDTH = 640;
const float SCREEN_HEIGHT = 480;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
GameObject* gTestGameObject1;
GameObject* gTestGameObject2;
GameObject* gTestGameObject3;


void MoveDot(Vector2 moveInput)
{
	float moveSpeed = 2.0f;
	moveInput.Normalize();

	Vector2 moveVector = moveInput * moveSpeed;
	moveVector = Vector2::WorldToSDL(moveVector);
	gTestGameObject1->transform->Translate(moveVector);

	if (Vector2::Magnitude(moveInput) == 0) return;
	Vector2 lookDirection = Vector2::Lerp(gTestGameObject1->transform->GetUp(), moveInput, 0.1f);

	gTestGameObject1->transform->LookAt(lookDirection);
}

void MoveDot2(Vector2 moveInput) 
{
	if (moveInput.y == 0) return;
	float moveSpeed = 2.0f;
	float rotationSpeed = 2.0f;

	Vector2 moveVector = gTestGameObject1->transform->GetUp() * moveInput.y * moveSpeed;
	moveVector = Vector2::WorldToSDL(moveVector);
	gTestGameObject1->transform->Translate(moveVector);

	gTestGameObject1->transform->Rotate(moveInput.x * rotationSpeed);
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

	ObjectManager::GetInstance()->SetRenderer(gRenderer);
	return success;
}

bool LoadMedia()
{
	//Loading success flag
	bool success = true;

	gTestGameObject1 = ObjectManager::GetInstance()->CreateGameObject("GO1", "Assets/bmp/dot.bmp", Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), 0.0f, nullptr);
	gTestGameObject2 = ObjectManager::GetInstance()->CreateGameObject("GO2", "Assets/bmp/dot.bmp", Vector2(SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 + 40), 0.0f, gTestGameObject1->transform);
	gTestGameObject3 = ObjectManager::GetInstance()->CreateGameObject("GO3", "Assets/bmp/dot.bmp", Vector2(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 + 30), 0.0f, gTestGameObject1->transform);

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

			InputManager::GetInstance()->UpdateInputManager(e);
		}

		MoveDot2(InputManager::GetInstance()->GetMoveInput());

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Update screen
		Transform* testTransform = gTestGameObject1->transform;
		Transform* testTransform2 = gTestGameObject2->transform;
		Transform* testTransform3 = gTestGameObject3->transform;

		gTestGameObject1->textureRenderer->Render(testTransform->GetPosition(), testTransform->GetRotation(), testTransform->GetScale());
		gTestGameObject2->textureRenderer->Render(testTransform2->GetPosition(), testTransform2->GetRotation(), testTransform2->GetScale());
		gTestGameObject3->textureRenderer->Render(testTransform3->GetPosition(), testTransform3->GetRotation(), testTransform3->GetScale());

		SDL_RenderPresent(gRenderer);
	}
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