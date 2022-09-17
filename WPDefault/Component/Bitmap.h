#pragma once

class Bitmap : public Transform, public Component
{
public:
	Bitmap(char* filePath, GameObject* gameObject = nullptr);
	Bitmap(int src, GameObject* gameObject = nullptr);
	// ���Ͽ��� ��Ʈ�� ȣ�� ������
	~Bitmap();

	void SetBitmap(int src);
	void SetBitmap(char* filePath);

	void Update();
	void Render();
	void UIRender(int x, int y, int type);

	// ���� Get�Լ�
	POINT GetSize() { return size; }
	HBITMAP GetBitmap() { return myBitmap; }
	BITMAP GetBitmapInfo() { return bitmapInfo; }

private:
	int src;
	HBITMAP		myBitmap;
	BITMAP		bitmapInfo;
	POINT size;

	// ������ ������ DIB�� DDB�� ��ȯ
	HBITMAP makeDDBFromDIB(HDC hdc, char* filePath);
};