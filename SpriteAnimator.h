#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Component.h"
#include "Vector.h"

class SpriteAnimator : public Component
{
public:
	SpriteAnimator(GameObject* gameobject ,SDL_Texture* loadedTexture,SDL_Renderer* renderer);
	~SpriteAnimator();
	void Update() override;
	std::vector<SDL_Rect*> SetFrames(int frames, int xTile, int yTile, int tileWidth, int tileHeight);
	void Render(int x, int y,Vector2 scale);
private:
	SDL_Texture* texture;
	std::vector<SDL_Rect*> framesRect;
	std::vector<SDL_Rect*> frameContainer;
	int width;
	int height;
	int currentFrame;
	int frameTime;
	SDL_Rect* currentClip;
	SDL_Renderer* renderer;
};