#include "ResourceManager.h"

ResourceManager* ResourceManager::resourceManager_ = nullptr;

ResourceManager::ResourceManager() 
{

}

ResourceManager::~ResourceManager()
{

}

ResourceManager* ResourceManager::GetInstance() 
{
	if (resourceManager_ == nullptr) 
	{
		resourceManager_ = new ResourceManager();
	}

	return resourceManager_;
}

void ResourceManager::ResetInstance() 
{
	delete resourceManager_;
	resourceManager_ = nullptr;
}

LoadedTexture ResourceManager::LoadTexture(std::string path, SDL_Renderer* renderer)
{
	LoadedTexture loadedTexture;
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
		else
		{
			loadedTexture.width = textureSurface->w;
			loadedTexture.height = textureSurface->h;
		}

		SDL_FreeSurface(textureSurface);
	}

	loadedTexture.texture = texture;
	return loadedTexture;
}

void ResourceManager::ShowError()
{
}
