#include "Framework.h"

extern HINSTANCE g_hInst;

// 리소스에서 비트맵 호출
Bitmap::Bitmap(int src, GameObject* gameObject)
	:Component(gameObject), src(src)
{
	if(gameObject != nullptr)
		SetParent(gameObject);

	myBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(src));

	GetObject(myBitmap,	// 비트맵 오브젝트 핸들
		sizeof(BITMAP),	// 크기
		&bitmapInfo);	// 비트맵 구조체 (값을 가져오기 위함)

	size = { bitmapInfo.bmWidth, bitmapInfo.bmHeight };
}

// 파일에서 비트맵 호출하는 생성자 추가
Bitmap::Bitmap(char* filePath, GameObject* gameObject)
	:Component(gameObject), src(0) // 파일 생성의 경우 src를 0으로 초기화.. 해도 되나..?
{
	if (gameObject != nullptr)
		SetParent(gameObject);
	// Renderer에서 hdc를 가져올 수 있을까..?
	HDC buffer = Renderer::Get()->GetBufferDC();
	// mybitmap에 파일에서 생성한 비트맵을 넣어줌
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

	GetObject(myBitmap,	// 비트맵 오브젝트 핸들
		sizeof(BITMAP),	// 크기
		&bitmapInfo);	// 비트맵 구조체 (값을 가져오기 위함)

	size = { bitmapInfo.bmWidth, bitmapInfo.bmHeight };
}
void Bitmap::SetBitmap(char* filePath)
{
	DeleteObject(myBitmap);


	HDC buffer = Renderer::Get()->GetBufferDC();
	// mybitmap에 파일에서 생성한 비트맵을 넣어줌
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
	// 비트맵에 대한 각종 정보
	HANDLE hFile;
	DWORD fileSize, dwRead;
	HBITMAP hBit;
	BITMAPFILEHEADER* fileHeader;
	BITMAPINFO* info;
	BITMAPINFOHEADER* infoHeader;
	LPBYTE lpMemBlock;
	char Path[MAX_PATH];
	// 현재 작업 경로를 가져와서 Path에 넣어주고
	GetCurrentDirectory(MAX_PATH, Path);
	// 문자열을 합해줌 => filePath입력을 짧게 해줌
	strcat_s(Path, MAX_PATH, filePath);

	// 파일 열기
	hFile = CreateFile(Path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	// 각종 정보 추가
	fileSize = GetFileSize(hFile, NULL);

	lpMemBlock = (LPBYTE)malloc(fileSize);
	fileHeader = (BITMAPFILEHEADER*)lpMemBlock;
	ReadFile(hFile, lpMemBlock, fileSize, &dwRead, NULL);
	CloseHandle(hFile);

	info = (BITMAPINFO*)(lpMemBlock + sizeof(BITMAPFILEHEADER));
	infoHeader = (BITMAPINFOHEADER*)(lpMemBlock + sizeof(BITMAPFILEHEADER));

	// DDB로 변환
	hBit = CreateDIBitmap(hdc, infoHeader, CBM_INIT, lpMemBlock + fileHeader->bfOffBits, info, DIB_RGB_COLORS);

	// 메모리 반환
	free(lpMemBlock);

	return hBit;
}
