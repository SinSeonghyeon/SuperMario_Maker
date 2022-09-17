#pragma once
/// <summary>
/// write by Ssreppa
/// 
/// winProc의 WM_CREATE 메세지에 Create,  winMain 메인 루프의 마지막에 Flip, 메인 루프 종료시에 Delete
/// winProc의 WM_PAINT 부분의 동작 Draw에 정의
/// </summary>


class Camera;

class Renderer
{
public:
	static void Create(HWND hWnd)
	{
		if (!instance) instance = new Renderer(hWnd);
	}
	static void Delete()
	{
		if (instance) delete instance;
	}
	static Renderer* Get() { return instance; }


	void FlipOnScreen() { InvalidateRect(hWnd, NULL, false); }//그리기 호출 함수
	void Render();//최종 출력하는 함수
	void Clear();
	// 비트맵 관련 DC얻어오는 함수
	HDC GetBufferDC() { return buffer; }
	// hWnd도 얻어옵시다..
	HWND GetHWnd() { return hWnd; }

	void SetCamera(Camera* cam) { camera = cam; }//카메라 세팅 함수
	Camera* GetCamera() { return camera; }
	///그리기 관련 함수
	void Draw(const HBITMAP& hBitmap, const BITMAP& bitmap, vector<float> xy);//비트맵 그리는 함수
	void Renderer::DrawLine(vector<float> xy_from, vector<float> xy_to, int Colors[3]);//선을 그리는 함수
	void DrawRect(vector<float> position, POINT size);//포지션에 중앙을 넣고, size에 한변의 길이
	//todo : DrawRect를 line으로 그리게 바꿀것, 가로 세로 길이 다르게 할것
	void DrawCircle(vector<float> position, int radius);
	//todo : Circle을 가운데 비우고 그릴수 있나? 안되면 점을 그려서 원을 그리게
	void DrawUI(UI _UI);
	// Grid 그리기
	void DrawGrid();

private:
	Renderer(HWND hWnd);
	~Renderer();
	static Renderer* instance;
	HFONT hFont;
	Camera* camera;

	HWND hWnd;

	HDC hdc, buffer, temp;
	PAINTSTRUCT ps;

	HBITMAP bufferBitmap;//버퍼
};