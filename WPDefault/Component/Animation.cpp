#include "Framework.h"
#include "Animation.h"

Animation::Animation(GameObject* gameObject, vector<Bitmap*> inputClip)
	:Component(gameObject), frameRate(0.3f), timeElapsed(0.0f), clips{}, currentClip(inputClip[0]), clipIndex(0), animSize(inputClip.size())
{
	for (Bitmap* clip : inputClip)
	{
		clip->SetParent(gameObject);

		clips.push_back(clip);
	}
}

Animation::~Animation()
{
	for (Bitmap* clip : clips)
	{
		delete clip;
	}
}

void Animation::Update()
{
	for (Bitmap* clip : clips)
		clip->UpdateWorld();

	timeElapsed += TIME->Delta();

	currentClip->Update();

	if (timeElapsed >= frameRate)
	{
		timeElapsed = 0;
		Filp();
	}

}

void Animation::Render()
{
	currentClip->Render();
}

void Animation::Filp()
{
	if (clipIndex < animSize - 1)
		currentClip = clips[++clipIndex];
	else
	{
		clipIndex = 0;
		currentClip = clips[clipIndex];
	}
}
