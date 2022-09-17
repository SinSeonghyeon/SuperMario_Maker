#include "Framework.h"


Renderer* Renderer::instance = nullptr;


Renderer::Renderer(HWND hWnd)
	:hWnd(hWnd), hdc(GetDC(hWnd))
{
	hFont = CreateFont(29, 0, 0, 0, 700, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_SCRIPT, "Fixedsys");
	bufferBitmap = CreateCompatibleBitmap(hdc, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	buffer = CreateCompatibleDC(hdc);
	temp = CreateCompatibleDC(hdc);
	(HBITMAP)SelectObject(buffer, bufferBitmap);
	SelectObject(buffer, hFont);
	camera = new Camera(0);

}

Renderer::~Renderer()
{
	ReleaseDC(hWnd, hdc);
	DeleteDC(buffer);
	DeleteDC(temp);
	DeleteObject(hFont);
	DeleteObject(bufferBitmap);
	delete camera;
}

//todo : 선 그리기
void Renderer::Draw(const HBITMAP& hBitmap, const BITMAP& bitmap, const vector<float> xy)
{
	if ((int)xy[0] - camera->position[0] < WINDOW_SIZE_X)
	{
		HBITMAP OldBitmap = (HBITMAP)SelectObject(temp, hBitmap);
		TransparentBlt(buffer,
			(int)xy[0] - camera->position[0], (int)xy[1] - camera->position[1],
			bitmap.bmWidth, bitmap.bmHeight,
			temp,
			0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(0, 255, 0));
		SelectObject(temp, OldBitmap);
	}
}

void Renderer::DrawLine(vector<float> xy_from, vector<float> xy_to, int Colors[3])
{
	if ((int)xy_from[0] - camera->position[0] < WINDOW_SIZE_X || (int)xy_to[0] - camera->position[0] < WINDOW_SIZE_X)
	{
		HPEN newPen = CreatePen(PS_SOLID, 2, RGB(Colors[0], Colors[1], Colors[2]));
		HPEN oldPen = (HPEN)SelectObject(buffer, newPen);

		MoveToEx(buffer, xy_from[0] - camera->position[0], xy_from[1] - camera->position[1], NULL);
		LineTo(buffer, xy_to[0] - camera->position[0], xy_to[1] - camera->position[1]);

		SelectObject(buffer, oldPen);
		DeleteObject(newPen);
	}
	
}

void Renderer::DrawRect(vector<float> position, POINT size)
{
	if ((int)position[0] - camera->position[0] < WINDOW_SIZE_X)
	{
		Rectangle(buffer,
			position[0] - camera->position[0],
			position[1] - camera->position[1],
			position[0] - camera->position[0] + size.x,
			position[1] - camera->position[1] + size.y);
	}
}

void Renderer::DrawCircle(vector<float> position, int radius)
{

}

void Renderer::DrawUI(UI _UI)
{
	RECT rt = { _UI.m_x,_UI.m_y ,_UI.m_x + 400,_UI.m_y + Renderer::Get()->GetCamera()->position[1]+100 };
	SetTextColor(buffer, RGB(255, 255, 255));
	SetBkMode(buffer, TRANSPARENT);
	DrawText(buffer, _UI.m_text, -1, &rt, DT_LEFT | DT_WORDBREAK);
}

void Renderer::DrawGrid()
{
	HPEN newPen, oldPen;
	newPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	oldPen = (HPEN)SelectObject(buffer, newPen);
	// 카메라 추가 해보기..
	// 세로 그리드(선)
		// 개수 Window_size_x / Tile_size = 30 => 30개 까지만 화면에 띄워줌
	int yLineCount = 0;
	int drawY = int(Renderer::Get()->GetCamera()->position[0]) / TILE_SIZE;

	while (yLineCount < 31)
	{
		MoveToEx(buffer, (drawY * TILE_SIZE) - Renderer::Get()->GetCamera()->position[0], 0, NULL);
		LineTo(buffer, (drawY * TILE_SIZE) - Renderer::Get()->GetCamera()->position[0], WINDOW_SIZE_Y);
		drawY++;
		yLineCount++;
	}
	
	// 가로 그리드(선)
		// 개수 Window_size_y / Tile_size = 20 => 20개 까지만 화면에 띄워줌
	int xLineCount = 0;
	int drawX = int(Renderer::Get()->GetCamera()->position[1]) / TILE_SIZE;
	while (xLineCount < 31)
	{
		MoveToEx(buffer, 0, (drawX * TILE_SIZE) - Renderer::Get()->GetCamera()->position[1], NULL);
		LineTo(buffer, WINDOW_SIZE_X, (drawX * TILE_SIZE) - Renderer::Get()->GetCamera()->position[1]);
		drawX++;
		xLineCount++;
	}
	
	SelectObject(buffer, oldPen);
	DeleteObject(newPen);
}

void Renderer::Clear()//배경 그리면 안해줘도 될듯
{
	PatBlt(buffer, 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, BLACKNESS);
}

void Renderer::Render()
{
	hdc = BeginPaint(hWnd, &ps);
	{
		if (camera != NULL)
		{
			BitBlt(hdc,
				0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y,
				buffer,
				0, 0,
				SRCCOPY);
		}
		else
		{
			BitBlt(hdc,
				0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y,
				buffer,
				0, 0,
				SRCCOPY);
		}
	}
	EndPaint(hWnd, &ps);
	Clear();
}