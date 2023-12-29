#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>

class ResourceManager
{
public:
	SDL_Texture* LoadTexture(std::string path, SDL_Renderer* renderer);
private:
	void ShowError();
};


