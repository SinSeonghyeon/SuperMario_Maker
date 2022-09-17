#pragma once

class Animation : public Component
{
public:
	Animation(GameObject* gameObject, vector<Bitmap*> inputClip);
	~Animation();

	void Update();

	void Render();
	//���� Ŭ���� �׸�

	//�ð��� üũ ��

	//�ð��� ���س��� �ð����� Ŀ���� ���� Ŭ������ �ѱ�

	void Filp();

	void Reset() { timeElapsed = 0.0f; clipIndex = 0; currentClip = clips[0]; }//�ִϸ��̼� ����۽ÿ�

	vector<Bitmap*> clips;
	Bitmap* currentClip;

private:
	int clipIndex;
	int animSize;
	float frameRate;//Ŭ���� �ѱ� ����
	float timeElapsed;//���� �ð� üũ
};