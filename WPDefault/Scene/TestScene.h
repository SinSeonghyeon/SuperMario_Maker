#pragma once

#include "GameObject/TestCollider/TestCollider.h"


class TestScene :public Scene
{
public:
	TestScene();
	~TestScene();
	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

private:

	Mario* mario;
	//TestCollider* floor;
	//TestCollider* k;

	Bitmap* a;
	//Bitmap* b;

	/// 맵 에디터용 변수들
	// 커서 타일
	Tile* m_tile;

	// 2차원 배열 타일의 x, y크기
	int tilesX, tilesY;
	int tempX, tempY;
	GameObject* tiles[WINDOW_SIZE_Y / TILE_SIZE][MAP_SIZE_X / TILE_SIZE];

	// 바닥 콜라이더
	TestCollider* ground[19];

	// 디버그용 타일사이즈
	//int tileSize();
};