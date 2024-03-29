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
	GameObject* gameObject;
	SDL_Rect* clip = NULL;

public:
	//Image dimensions
	float width;
	float height;
	bool disableUpdateRender;
	SDL_RendererFlip flip;

	//Initializes variables
	TextureRenderer();
	TextureRenderer(GameObject* gameObject , std::string texturePath = "");

	//Deallocates memory
	~TextureRenderer();

	void Update() override;

	//Initialize component
	void Init(std::string path);

	//Loads image at specified path
	void LoadFromFile(std::string path);

	SDL_Texture* GetTexture();

	//Deallocates texture
	void Free();

	//Set color modulation
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void SetBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void SetAlpha(Uint8 alpha);

	void SetTexture(SDL_Texture* texture, SDL_Rect* currentClip);

	//Renders texture at given point
	void Render(Vector2 position, float angle = 0.0f,const Vector2& scale = Vector2(1,1), SDL_FPoint* center = NULL);
};
