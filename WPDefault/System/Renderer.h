#pragma once
/// <summary>
/// write by Ssreppa
/// 
/// winProc�� WM_CREATE �޼����� Create,  winMain ���� ������ �������� Flip, ���� ���� ����ÿ� Delete
/// winProc�� WM_PAINT �κ��� ���� Draw�� ����
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
	void Draw(const HBITMAP& hBitmap, const BITMAP& bitmap, vector<float> xy);//��Ʈ�� �׸��� �Լ�
	void Renderer::DrawLine(vector<float> xy_from, vector<float> xy_to, int Colors[3]);//���� �׸��� �Լ�
	void DrawRect(vector<float> position, POINT size);//�����ǿ� �߾��� �ְ�, size�� �Ѻ��� ����
	//todo : DrawRect�� line���� �׸��� �ٲܰ�, ���� ���� ���� �ٸ��� �Ұ�
	void DrawCircle(vector<float> position, int radius);
	//todo : Circle�� ��� ���� �׸��� �ֳ�? �ȵǸ� ���� �׷��� ���� �׸���
	void DrawUI(UI _UI);
	// Grid �׸���
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

	HBITMAP bufferBitmap;//����
};