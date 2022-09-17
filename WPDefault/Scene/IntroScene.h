#pragma once

class IntroScene :public Scene
{
public:
	IntroScene();
	~IntroScene();

	virtual void Update() override;

	virtual void Render() override;

private:
	int m_Num;
	Bitmap* BackGround;
	Bitmap* LOGO;
	Bitmap* m_Cursor;	
};