#include "Framework.h"

extern HINSTANCE g_hInst;

// ���ҽ����� ��Ʈ�� ȣ��
Bitmap::Bitmap(int src, GameObject* gameObject)
	:Component(gameObject), src(src)
{
	if(gameObject != nullptr)
		SetParent(gameObject);

	myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(src));

	GetObject(myBitmap,	// ��Ʈ�� ������Ʈ �ڵ�
		sizeof(BITMAP),	// ũ��
		&bitmapInfo);	// ��Ʈ�� ����ü (���� �������� ����)

	size = { bitmapInfo.bmWidth, bitmapInfo.bmHeight };
}

// ���Ͽ��� ��Ʈ�� ȣ���ϴ� ������ �߰�
Bitmap::Bitmap(char* filePath, GameObject* gameObject)
	:Component(gameObject), src(0) // ���� ������ ��� src�� 0���� �ʱ�ȭ.. �ص� �ǳ�..?
{
	if (gameObject != nullptr)
		SetParent(gameObject);
	// Renderer���� hdc�� ������ �� ������..?
	HDC buffer = Renderer::Get()->GetBufferDC();
	// mybitmap�� ���Ͽ��� ������ ��Ʈ���� �־���
	myBitmap = makeDDBFromDIB(buffer, filePath);

	GetObject(myBitmap, sizeof(BITMAP), &bitmapInfo);

	size = { bitmapInfo.bmWidth, bitmapInfo.bmHeight };
}

Bitmap::~Bitmap()
{
	DeleteObject(myBitmap);
}
void Bitmap::SetBitmap(int _src)
{
	DeleteObject(myBitmap);
	src = _src;
	myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(src));

	GetObject(myBitmap,	// ��Ʈ�� ������Ʈ �ڵ�
		sizeof(BITMAP),	// ũ��
		&bitmapInfo);	// ��Ʈ�� ����ü (���� �������� ����)

	size = { bitmapInfo.bmWidth, bitmapInfo.bmHeight };
}
void Bitmap::SetBitmap(char* filePath)
{
	DeleteObject(myBitmap);


	HDC buffer = Renderer::Get()->GetBufferDC();
	// mybitmap�� ���Ͽ��� ������ ��Ʈ���� �־���
	myBitmap = makeDDBFromDIB(buffer, filePath);

	GetObject(myBitmap, sizeof(BITMAP), &bitmapInfo);

	size = { bitmapInfo.bmWidth, bitmapInfo.bmHeight };

}
void Bitmap::Update()
{
	UpdateWorld();
}

void Bitmap::Render()
{
	Renderer::Get()->Draw(myBitmap, bitmapInfo, WorldPos());

	Renderer2::Get()->Draw(myBitmap, bitmapInfo, WorldPos());

}
void Bitmap::UIRender(int x, int y, int type = 0)
{
	if (type == 0)
	{
		Renderer2::Get()->DrawPanel(myBitmap, bitmapInfo, WorldPos(), x, y);
	}
	else
	{
		Renderer2::Get()->ButtonDraw(myBitmap, bitmapInfo, WorldPos(), x, y);
	}

}

HBITMAP Bitmap::makeDDBFromDIB(HDC hdc, char* filePath)
{
	// ��Ʈ�ʿ� ���� ���� ����
	HANDLE hFile;
	DWORD fileSize, dwRead;
	HBITMAP hBit;
	BITMAPFILEHEADER* fileHeader;
	BITMAPINFO* info;
	BITMAPINFOHEADER* infoHeader;
	LPBYTE lpMemBlock;
	char Path[MAX_PATH];
	// ���� �۾� ��θ� �����ͼ� Path�� �־��ְ�
	GetCurrentDirectory(MAX_PATH, Path);
	// ���ڿ��� ������ => filePath�Է��� ª�� ����
	strcat_s(Path, MAX_PATH, filePath);

	// ���� ����
	hFile = CreateFile(Path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	// ���� ���� �߰�
	fileSize = GetFileSize(hFile, NULL);

	lpMemBlock = (LPBYTE)malloc(fileSize);
	fileHeader = (BITMAPFILEHEADER*)lpMemBlock;
	ReadFile(hFile, lpMemBlock, fileSize, &dwRead, NULL);
	CloseHandle(hFile);

	info = (BITMAPINFO*)(lpMemBlock + sizeof(BITMAPFILEHEADER));
	infoHeader = (BITMAPINFOHEADER*)(lpMemBlock + sizeof(BITMAPFILEHEADER));

	// DDB�� ��ȯ
	hBit = CreateDIBitmap(hdc, infoHeader, CBM_INIT, lpMemBlock + fileHeader->bfOffBits, info, DIB_RGB_COLORS);

	// �޸� ��ȯ
	free(lpMemBlock);

	return hBit;
}
