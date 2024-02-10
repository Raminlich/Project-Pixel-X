#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Component.h"
#include "Vector.h"
#include "TextureRenderer.h"

class SpriteAnimator : public Component
{
public:
	SpriteAnimator(GameObject* gameobject,TextureRenderer* textureRenderer);
	~SpriteAnimator();
	void Update() override;
	std::vector<SDL_Rect*> SetFrames(int frames, int xTile, int yTile, int tileWidth, int tileHeight);
private:
	TextureRenderer* renderer;
	SDL_Texture* texture;
	std::vector<SDL_Rect*> framesRect;
	std::vector<SDL_Rect*> frameContainer;
	int width;
	int height;
	int currentFrame;
	int frameTime;
	SDL_Rect* currentClip;
};