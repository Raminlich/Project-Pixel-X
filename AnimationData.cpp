#include "AnimationData.h"
#include "iostream"

AnimationClip* AnimationData::GetAnimationClip(const char* animationName)
{
	for (AnimationClip animationClip : mAnimationClips) 
	{
		if (animationClip.name == animationName) 
		{
			return &animationClip;
		}
	}
	SDL_Log("No Clips were found by the name of {}", animationName);
	return nullptr;
}

void AnimationData::AddAnimationClip(AnimationClip animationClip)
{
	mAnimationClips.emplace_back(animationClip);
}
