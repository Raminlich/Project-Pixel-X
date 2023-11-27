#include "SDL2/SDL.h"
#include "fmt/format.h"
#include "iostream"
#include "InputManager.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

InputManager* gInputManager;

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<< fmt::format("Could could to initialize! SDL_Error : {0}", SDL_GetError()) << std::endl;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Pixel-X", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << fmt::format("Could could to initialize! SDL_Error : {0}", SDL_GetError()) << std::endl;
		}
		else
		{
			std::cout << "SDL successfuly initialized!"<<std::endl;
			screenSurface = SDL_GetWindowSurface(window);
			gInputManager = new InputManager();
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Event e;
			bool quit = false;
			while (quit == false)
			{
				while (SDL_PollEvent(&e))
				{
					if ((e.type == SDL_QUIT))
					{
						quit = true;
					}

					gInputManager->UpdateInputManager(e);
				}
			}
		}
		SDL_DestroyWindow(window);

		SDL_Quit();

		return 0;
	}
}