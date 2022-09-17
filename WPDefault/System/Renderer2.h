#pragma once
#pragma once
/// <summary>
/// write by Ssreppa
/// 
/// winProc�� WM_CREATE �޼����� Create,  winMain ���� ������ �������� Flip, ���� ���� ����ÿ� Delete
/// winProc�� WM_PAINT �κ��� ���� Draw�� ����
/// </summary>


class Camera;

class Renderer2
{
public:
	static void Create(HWND hWnd)
	{
		if (!instance) instance = new Renderer2(hWnd);
	}
	static void Delete()
	{
		if (instance) delete instance;
	}
	static Renderer2* Get() { return instance; }


	void FlipOnScreen() { InvalidateRect(hWnd, NULL, false); }//�׸��� ȣ�� �Լ�
	void Render();//���� ����ϴ� �Լ�
	void Clear();
	// ��Ʈ�� ���� DC������ �Լ�
	HDC GetBufferDC() { return buffer; }
	// hWnd�� ���ɽô�..
	HWND GetHWnd() { return hWnd; }

	void SetCamera(Camera* cam) { camera = cam; }//ī�޶� ���� �Լ�
	Camera* GetCamera() { return camera; }
	///�׸��� ���� �Լ�
	void Draw(const HBITMAP& hBitmap, const BITMAP& bitmap, vector<float> xy);
	void DrawPanel(const HBITMAP& hBitmap, const BITMAP& bitmap, vector<float> xy, int width, int high);
	void ButtonDraw(const HBITMAP& hBitmap, const BITMAP& bitmap, vector<float> xy, int width, int high);
	//��Ʈ�� �׸��� �Լ�
	void Renderer2::DrawLine(vector<float> xy_from, vector<float> xy_to, int Colors[3]);//���� �׸��� �Լ�
	void DrawRect(vector<float> position, POINT size);//�����ǿ� �߾��� �ְ�, size�� �Ѻ��� ����
	//todo : DrawRect�� line���� �׸��� �ٲܰ�, ���� ���� ���� �ٸ��� �Ұ�
	void DrawCircle(vector<float> position, int radius);
	//todo : Circle�� ��� ���� �׸��� �ֳ�? �ȵǸ� ���� �׷��� ���� �׸���
	void DrawUI(UI _UI);
	// Grid �׸���
	void DrawGrid();

private:
	Renderer2(HWND hWnd);
	~Renderer2();
	static Renderer2* instance;
	HFONT hFont;
	Camera* camera;

	HWND hWnd;

	HDC hdc, buffer, temp, temp2 ;
	PAINTSTRUCT ps;

	HBITMAP bufferBitmap;//����
};