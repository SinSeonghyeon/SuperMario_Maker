#include "Framework.h"
KeyBoard* KeyBoard::instance = nullptr;

KeyBoard::KeyBoard()
	: curState{}, oldState{}, mapState{}
{
}

KeyBoard::~KeyBoard()
{
}

void KeyBoard::Update()
{
	memcpy(oldState, curState, sizeof(oldState));

	ZeroMemory(curState, sizeof(curState));
	ZeroMemory(mapState, sizeof(mapState));
	


	GetKeyboardState(curState);


	for (UINT i = 0; i < KEYMAX; i++)
	{
		byte key = curState[i] & 0x80;
        curState[i] = key ? 1 : 0;

		int old = oldState[i];
		int cur = curState[i];

		if (old == 0 && cur == 1)
			mapState[i] = DOWN;
		else if (old == 1 && cur == 0)
			mapState[i] = UP;
		else if (old == 1 && cur == 1)
			mapState[i] = PRESS;
		else
			mapState[i] = NONE;
	}

	GetKeyState(0);
}
