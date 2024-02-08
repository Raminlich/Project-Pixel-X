#include "SpriteAnimator.h"

SpriteAnimator::SpriteAnimator(GameObject* gameObject,SDL_Texture* loadedTexture,SDL_Renderer* renderer) :
	 currentFrame(0) , frameTime(0)
{
	texture = loadedTexture;
	width = 0;
	height = 0;
	this->renderer = renderer;
}

SpriteAnimator::~SpriteAnimator()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void SpriteAnimator::Update()
{

}

std::vector<SDL_Rect*> SpriteAnimator::SetFrames(int frames, int xTile, int yTile, int tileWidth, int tileHeight)
{
	framesRect.clear();
	framesRect.resize(frames);
	for (int i = 0; i < frames; i++)
	{
		framesRect[i] = new SDL_Rect;
		framesRect[i]->x = i * xTile;
		framesRect[i]->y = i * yTile;
		framesRect[i]->w = tileWidth;
		framesRect[i]->h = tileHeight;
	}
	frameContainer = framesRect;
	currentClip = frameContainer[currentFrame];
	return framesRect;
}

void SpriteAnimator::Render(int x, int y , Vector2 scale)
{
	SDL_Rect quad = { x,y,width,height };


	if (currentClip != NULL)
	{
		quad.w = currentClip->w * scale.x;
		quad.h = currentClip->h * scale.y;
	}

	if (frameTime >= frameContainer.size())
	{
		currentClip = frameContainer[currentFrame];
		currentFrame++;
		if (currentFrame >= frameContainer.size())
		{
			currentFrame = 0;
		}
		frameTime = 0;
	}
	frameTime++;

	SDL_RenderCopy(renderer, texture, currentClip, &quad);
}
