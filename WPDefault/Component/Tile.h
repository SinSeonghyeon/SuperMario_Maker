#pragma once
class Tile:public Component
{
public:
	// ������ �� ��Ʈ���� �߰�����
	Tile(char* filePath, GameObject* gameObject = nullptr);
	Tile(int src, GameObject* gameObject = nullptr);
	~Tile();

	// ������ Ȯ��
	Transform* GetTilePos() { return tileTransform; }
	
	// Ÿ�� ��Ʈ�� ����
	void SetBitmap(char* filePath);

	// Grid Snap Render
	void SetPosition(long x, long y);
	void Update();
	void Render();

private:
	// �� Ÿ���� ������ �ִ� �̹���
	Bitmap* tileBitmap;
	// Ÿ���� ��ġ
	Transform* tileTransform;
	// Ÿ���� ũ��
	POINT tileSize;
};

