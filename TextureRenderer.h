#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Component.h"
#include "Vector.h"

#include <iostream>

class TextureRenderer : public Component
{
private:
	//SDL_Renderer for window we want to render
	SDL_Renderer* mRenderer;
	//The actual hardware texture
	SDL_Texture* mTexture;

public:
	//Image dimensions
	float width;
	float height;

	//Initializes variables
	TextureRenderer();
	TextureRenderer(SDL_Renderer* sdlRenderer);

	//Deallocates memory
	~TextureRenderer();

	void Init(std::string path, Vector2 initialPosition);

	//Loads image at specified path
	bool LoadFromFile(std::string path);

	//Deallocates texture
	void Free();

	//Set color modulation
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void SetBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void SetAlpha(Uint8 alpha);

	//Renders texture at given point
	void Render(Vector2 position, SDL_Rect* clip = NULL, double angle = 0.0, SDL_FPoint* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
