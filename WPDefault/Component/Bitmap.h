#pragma once

class Bitmap : public Transform, public Component
{
public:
	Bitmap(char* filePath, GameObject* gameObject = nullptr);
	Bitmap(int src, GameObject* gameObject = nullptr);
	// 파일에서 비트맵 호출 생성자
	~Bitmap();

	void SetBitmap(int src);
	void SetBitmap(char* filePath);

	void Update();
	void Render();
	void UIRender(int x, int y, int type);

	// 각종 Get함수
	POINT GetSize() { return size; }
	HBITMAP GetBitmap() { return myBitmap; }
	BITMAP GetBitmapInfo() { return bitmapInfo; }

private:
	int src;
	HBITMAP		myBitmap;
	BITMAP		bitmapInfo;
	POINT size;

	// 교수님 예제의 DIB를 DDB로 전환
	HBITMAP makeDDBFromDIB(HDC hdc, char* filePath);
};