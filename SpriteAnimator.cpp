#include "SpriteAnimator.h"

SpriteAnimator::SpriteAnimator(GameObject* gameObject , TextureRenderer* textureRenderer) :
	currentFrame(0), frameTime(0) , renderer(textureRenderer) , width(0) , height(0) , texture(textureRenderer->GetTexture())
{
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
	renderer->SetTexture(texture, currentClip);
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

