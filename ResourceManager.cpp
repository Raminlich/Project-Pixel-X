#include "ResourceManager.h"

SDL_Texture* ResourceManager::LoadTexture(std::string path, SDL_Renderer* renderer)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* textureSurface = IMG_Load(path.c_str());
	if (textureSurface == NULL)
	{
		SDL_LogError(0, IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
		if (texture == NULL)
		{
			SDL_LogError(0, IMG_GetError());
		}
		SDL_FreeSurface(textureSurface);
	}
	return texture;
}

void ResourceManager::ShowError()
{
}
