#pragma once
class GameoverScene : public Scene
{
public:
	GameoverScene();
	~GameoverScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	int m_Num;
	Bitmap* BackGround;
	Bitmap* GameOverBmp;
	Bitmap* m_Cursor;
};

