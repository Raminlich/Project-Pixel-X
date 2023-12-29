#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>

struct LoadedTexture
{
	SDL_Texture* texture;
	int width;
	int height;
};

class ResourceManager
{
private:
	static ResourceManager* resourceManager_;
	ResourceManager();
	~ResourceManager();
	void ShowError();
public:

	ResourceManager(ResourceManager& other) = delete;
	ResourceManager operator = (const ResourceManager& other) = delete;

	static ResourceManager* GetInstance();
	static void ResetInstance();

	LoadedTexture LoadTexture(std::string path, SDL_Renderer* renderer);
};


