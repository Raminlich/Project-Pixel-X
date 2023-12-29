#pragma once
#include "SDL2/SDL.h"
#include "vector"

struct AnimationClip 
{
	const char* name;
	const int FrameInterval;
	std::vector<SDL_Rect*> clipsData;
};

class AnimationData
{
private:
	std::vector <AnimationClip> mAnimationClips;

public:
	//Retruns animation clip based on name
	AnimationClip* GetAnimationClip(const char* animationName);

	//Adds an animation clip to the list of AnimationClips
	void AddAnimationClip(AnimationClip animationClip);
};