#include "TextureRenderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Transform.h"

TextureRenderer::TextureRenderer(GameObject* gameObject, SDL_Renderer* sdlRenderer, std::string texturePath)
	: Component(gameObject), mRenderer(sdlRenderer)
{
	//Initialize
	Init(texturePath);
}

TextureRenderer::~TextureRenderer()
{
	//Deallocate
	Free();
}

void TextureRenderer::Update()
{
	Transform* transform = gameObject->transform;
		Render(transform->GetPosition(), transform->GetRotation(), transform->GetScale());
}

void TextureRenderer::Init(std::string path)
{
	//Init
	LoadFromFile(path);
	Render(gameObject->transform->GetPosition());
	flip = SDL_FLIP_NONE;
}

void TextureRenderer::LoadFromFile(std::string path)
{
	//Get rid of preexisting texture
	Free();

	//The final texture
	LoadedTexture loadedTexture = ResourceManager::GetInstance()->LoadTexture(path,mRenderer);
	width = loadedTexture.width;
	height = loadedTexture.height;
	mTexture = loadedTexture.texture;
}

SDL_Texture* TextureRenderer::GetTexture()
{
	return mTexture;
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