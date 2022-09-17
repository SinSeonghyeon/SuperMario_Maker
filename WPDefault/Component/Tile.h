#pragma once
class Tile:public Component
{
public:
	// 생성할 때 비트맵을 추가해줌
	Tile(char* filePath, GameObject* gameObject = nullptr);
	Tile(int src, GameObject* gameObject = nullptr);
	~Tile();

	// 포지션 확인
	Transform* GetTilePos() { return tileTransform; }
	
	// 타일 비트맵 변경
	void SetBitmap(char* filePath);

	// Grid Snap Render
	void SetPosition(long x, long y);
	void Update();
	void Render();

private:
	// 각 타일이 가지고 있는 이미지
	Bitmap* tileBitmap;
	// 타일의 위치
	Transform* tileTransform;
	// 타일의 크기
	POINT tileSize;
};

