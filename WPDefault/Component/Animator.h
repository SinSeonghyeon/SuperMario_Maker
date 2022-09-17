#pragma once

class Animator : public Component
{
public:
	Animator(GameObject* gameobject);
	~Animator();

	void AddAnimation(int state, Animation* animation);

	void SetAnimation(int state);


	void Update();


	void Play();

private:

	Animation* currentAnimation;
	map<int,Animation*> animations;
};