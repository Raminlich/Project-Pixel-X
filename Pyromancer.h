#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "fmt/format.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector.h"
#include "SpriteAnimator.h"
#include "map"
#include <iostream>
#include "GameContext.h"

class Pyromancer
{
public:
	Pyromancer();
	bool LoadMedia();
};