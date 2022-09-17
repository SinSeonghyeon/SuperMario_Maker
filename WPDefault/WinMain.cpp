///
/// BitMap ���� 4.
/// MemBlt
/// 2019.11.08 ����ȯ
#include "Framework.h"

HINSTANCE g_hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam);

/// ��Ʈ�� �ڵ�
/// �뵵 : �޸� ��Ʈ��
Program* program;

/// WinMain �Լ� : ������ ���α׷��� ���� ������ ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR	  lpCmdLine,
	int		  nCmdShow)
{
	char	  szAppName[] = "SuperMario";
	MSG      msg;
	HWND hWnd;
	WNDCLASS wndclass;

	g_hInst = hInstance;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	/// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	wndclass.hCursor= LoadCursor(NULL, IDC_CROSS);
	wndclass.lpfnWndProc = ChildProc;
	wndclass.lpszClassName = "ChildCls";
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	RegisterClass(&wndclass);

	/// ���� ����
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		100, 100, WINDOW_SIZE_X + 16, WINDOW_SIZE_Y + 39,
		NULL, NULL, hInstance, NULL);//���� ������� ������ ������� ���� �ȸ¾Ƽ� �ϵ��ڵ� ��, ���� ��

	
	

	if (!hWnd) return FALSE;



	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);







	/// �޽��� ����
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else
		{
			{
				TIME->Update();
				KEYBOARD->Update();
				
			}
			{
				program->Update();
				program->Render();
			}
			Renderer::Get()->FlipOnScreen();
			Renderer2::Get()->FlipOnScreen();

		}

	}

	{
		Time::Delete();
		KeyBoard::Delete();
		Renderer::Delete();
		Renderer2::Delete();
		GameObjectManager::Delete();
	}



	return (int)msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static HWND _childhwnd;
	switch (iMessage)
	{
	case WM_CREATE:
		GameObjectManager::Create();
		Renderer::Create(hWnd);
		KeyBoard::Create();
		Time::Create();
		program = new Program();

		CreateWindow("ChildCls",
			"ChildCls",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			100 + WINDOW_SIZE_X, 100, WINDOW_SIZE_X + 16, WINDOW_SIZE_Y + 39,
			hWnd, NULL, g_hInst, NULL);
		return 0;
	case WM_PAINT:
		Renderer::Get()->Render();
		


		return 0;
	case WM_LBUTTONDOWN:
		return 0;

		// �޸� ��Ʈ���� �ı��Ѵ�.
	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}



LRESULT CALLBACK ChildProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hMemDC, hAlpha, hdc;
	HBITMAP hBitmap, bBmpAlpha;
	PAINTSTRUCT ps;

	switch (uMsg) {
	case WM_CREATE:
		Renderer2::Create(hWnd);
		return 0;
	
	case WM_RBUTTONDOWN: // ���콺 ���� ��ư�� ���� ���
	case WM_LBUTTONDOWN: // ���콺 ���� ��ư�� ���� ���
		GameManager::GetInstance()->m_UIManager.ClickButton(LOWORD(lParam), HIWORD(lParam));
		GameManager::GetInstance()->m_ParticleManager.Play(LOWORD(lParam) + RENDERER2->GetCamera()->position[0], HIWORD(lParam));
		return 0;
	case WM_RBUTTONUP: // ���콺 ���� ��ư�� ���� ���
	case WM_LBUTTONUP:
		GameManager::GetInstance()->m_UIManager.ClickButtonUp();

		return 0;
	case WM_PAINT:
		Renderer2::Get()->Render();


		return 0;


		
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);

	}

}