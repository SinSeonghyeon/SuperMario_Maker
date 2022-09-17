#include "Framework.h"
#include "Animator.h"


Animator::Animator(GameObject* gameobject)
	:Component(gameobject)
{


}

Animator::~Animator()
{

}

void Animator::AddAnimation(int state, Animation* animation)
{
	animations[state] = animation;
}

void Animator::SetAnimation(int state)
{
	if (currentAnimation != animations[state])
	{
		currentAnimation = animations[state];
		currentAnimation->Update();
	}

}

void Animator::Update()
{
	if (currentAnimation == nullptr)
		currentAnimation = animations[0];
		currentAnimation->Update();
}

void Animator::Play()
{
	if (currentAnimation == nullptr)
		currentAnimation = animations[0];
	if (currentAnimation != nullptr)
		currentAnimation->Render();
}