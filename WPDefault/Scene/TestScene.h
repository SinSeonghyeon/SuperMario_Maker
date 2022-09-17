#pragma once

#include "GameObject/TestCollider/TestCollider.h"


class TestScene :public Scene
{
public:
	TestScene();
	~TestScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

private:

	Mario* mario;
	//TestCollider* floor;
	//TestCollider* k;

	Bitmap* a;
	//Bitmap* b;

	/// �� �����Ϳ� ������
	// Ŀ�� Ÿ��
	Tile* m_tile;

	// 2���� �迭 Ÿ���� x, yũ��
	int tilesX, tilesY;
	int tempX, tempY;
	GameObject* tiles[WINDOW_SIZE_Y / TILE_SIZE][MAP_SIZE_X / TILE_SIZE];

	// �ٴ� �ݶ��̴�
	TestCollider* ground[19];

	// ����׿� Ÿ�ϻ�����
	//int tileSize();
};