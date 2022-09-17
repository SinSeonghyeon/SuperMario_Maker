#pragma once

#define KEYMAX 256

class KeyBoard
{
private:
	enum
	{
		NONE,
		DOWN,
		UP,
		PRESS
	};

	BYTE curState[KEYMAX];
	BYTE oldState[KEYMAX];
	BYTE mapState[KEYMAX];

	static KeyBoard* instance;

	KeyBoard();
	~KeyBoard();

public:
	static KeyBoard* Get() { return instance; }
	static void Create() { instance = new KeyBoard(); }
	static void Delete() { delete instance; }

	void Update();

	bool Down(UINT key) { return mapState[key] == DOWN; }
	bool Up(UINT key) { return mapState[key] == UP; }
	bool Press(UINT key) { return mapState[key] == PRESS; }
};