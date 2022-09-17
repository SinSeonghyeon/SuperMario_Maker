#pragma once

class UI
{
public:
	int m_x;
	int m_y;
	char m_text[50];

	UI(int _x, int _y, char* str)
	{
		m_x = _x;
		m_y = _y;
		wsprintf(m_text, str);
	}
};
class Button
{
public:
	bool isClick = false;
	int m_x;
	int m_y;
	int size_x;
	int size_y;
	Bitmap* m_Up;
	Bitmap* m_Down;
	Bitmap* m_Image;
	Button(int x, int y, int width, int high, int BitmapNum = IDB_Cursor)
	{
		m_x = x;
		m_y = y;
		size_x = width;
		size_y = high;
		m_Image = new Bitmap(IDB_Cursor);
		m_Up = new Bitmap(IDB_BUTTONUP);
		m_Down = new Bitmap(IDB_BUTTONDOWN);
		Update();
	}
	~Button()
	{
		delete m_Image;
		delete m_Up;
		delete m_Down;
	}
	void Update()
	{
		m_Image->position[0] = m_x+15;
		m_Image->position[1] = m_y+15;

		m_Up->position[0] = m_x;
		m_Up->position[1] = m_y;

		m_Down->position[0] = m_x;
		m_Down->position[1] = m_y;

		m_Image->Update();
		m_Up->Update();
		m_Down->Update();
	}
	void Render()
	{
		m_Up->UIRender(size_x, size_y, 1);
		if (isClick)
			m_Down->UIRender(size_x, size_y, 1);

		m_Image->UIRender(size_x - 30, size_y - 30, 1);

	}

	void OnClickDown();

	void OnClickUp();

};
class Panel
{
public:
	int m_x;
	int m_y;
	int size_x;
	int size_y;
	int count;

	Bitmap* m_Image;
	Button* m_Button[20];
	Panel(int x, int y, int width, int high, int type, int Count = 10, int BitmapNum = IDB_PANEL)//type은 0이나 1 // 가로 세로
	{
		m_x = x;
		m_y = y;
		size_x = width;
		size_y = high;
		m_Image = new Bitmap(IDB_PANEL);
		count = Count;

		m_Image->position[0] = m_x;
		m_Image->position[1] = m_y;
		m_Image->Update();
		if (type == 0)
		{
			widthInit(Count);
		}
		else
			highInit(Count);
	}
	~Panel()
	{
		delete m_Image;
		for (int i = 0; i < count; i++)
		{
			delete m_Button[i];
		}
	}
	void Update()
	{
		m_Image->position[0] = m_x;
		m_Image->position[1] = m_y;
	}
	void Render()
	{
		m_Image->UIRender(size_x, size_y, 0);
		for (int i = 0; i < count; i++)
		{
			m_Button[i]->Render();
		}
	}

	void widthInit(int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			m_Button[i] = new Button(m_x + 10 + (i * ((size_x - 10) / Count)), m_y + 10, (size_x - 200) / Count, size_y - 20, 100);
		}
	}
	void highInit(int Count)
	{
		for (int i = 0; i < Count; i++)
		{
			m_Button[i] = new Button(m_x + 10, m_y + 10 + (i * ((size_y - 10) / Count)), size_x - 20, (size_y - 100) / Count);
		}
	}


};


class UIManager
{
	int index = 0;
public:
	UIManager();
	~UIManager();

	//list<UI> m_UIList;
	UI* m_UIList[10] = { NULL };
	Panel* ButtonPanel = NULL;
	void CreateInGame();
	void CreateGameOver();
	void ReStart();
	void CreateUI(int x, int y, char* str);
	void Start();
	void MarioDie();
	void Update();
	void ClickButton(int mousex, int mousey);
	void ClickButtonUp();
	void Render();
	void GameoverUpdate();
	void GameoverRender();
};