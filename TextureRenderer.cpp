#include "TextureRenderer.h"
#include "Transform.h"
#include "GameObject.h"

TextureRenderer::TextureRenderer(GameObject* gameObject,SDL_Renderer* sdlRenderer, std::string texturePath)
	: Component(gameObject) ,mRenderer(sdlRenderer)
{
	//Initialize
	Init(texturePath);
}

TextureRenderer::~TextureRenderer()
{
	//Deallocate
	Free();
}

void TextureRenderer::Init(std::string path)
{
	//Init
	LoadFromFile(path);
	Render(gameObject->transform->GetPosition());
	flip = SDL_FLIP_NONE;
}

bool TextureRenderer::LoadFromFile(std::string path)
{
	//Get rid of preexisting texture
	Free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		//SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void TextureRenderer::Free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		width = 0;
		height = 0;
	}
}

void TextureRenderer::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void TextureRenderer::SetBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void TextureRenderer::SetAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void TextureRenderer::Render(Vector2 position, float angle, const Vector2& scale, SDL_Rect* clip, SDL_FPoint* center)
{
	//Set rendering space and render to screen
	SDL_FRect renderQuad = { position.x, position.y, width, height };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	renderQuad.w *= scale.x;
	renderQuad.h *= scale.y;

	//Render to screen
	SDL_RenderCopyExF(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}