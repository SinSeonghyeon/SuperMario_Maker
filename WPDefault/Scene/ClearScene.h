#pragma once
class Scene;
class ClearScene : public Scene
{
public:
	ClearScene();
	~ClearScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	int m_Num;
	Bitmap* BackGround;
	Bitmap* GameOverBmp;
	Bitmap* m_Cursor;
};

