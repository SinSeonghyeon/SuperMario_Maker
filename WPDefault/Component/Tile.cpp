#include "Framework.h"
#include "Tile.h"

Tile::Tile(char* filePath, GameObject* gameObject /*= nullptr*/)
	:Component(gameObject)
{
	// ��Ʈ�� ���� ��������
	tileBitmap = new Bitmap(filePath, gameObject);
	tileSize = tileBitmap->GetSize();
	// �ʱ� ���� 0, 0
	tileTransform = new Transform(0.0f, 0.0f);
}

Tile::Tile(int src, GameObject* gameObject /*= nullptr*/)
	:Component(gameObject)
{
	// ��Ʈ�� ���� ��������
	tileBitmap = new Bitmap(src, gameObject);
	tileSize = tileBitmap->GetSize();
	// �ʱ� ���� 0, 0
	tileTransform = new Transform(0.0f, 0.0f);
}

Tile::~Tile()
{
	delete tileBitmap;
	delete tileTransform;
}

void Tile::SetBitmap(char* filePath)
{
	// ù ��Ʈ���� ����?
	delete tileBitmap;
	// �� ���� ��������
	tileBitmap = new Bitmap(filePath);
	tileSize = tileBitmap->GetSize();
}

void Tile::SetPosition(long x, long y)
{
	// ���콺 �� �� ���� �޾Ƽ�
	// ��� pixel���� �����´�.
	long mouseX = x / TILE_SIZE;
	long mouseY = y / TILE_SIZE;

	mouseX = mouseX * TILE_SIZE;
	mouseY = mouseY * TILE_SIZE;

	tileTransform->position[0] = mouseX;
	tileTransform->position[1] = mouseY;
}

void Tile::Update()
{
	tileTransform->UpdateWorld();
}

void Tile::Render()
{
	Renderer::Get()->Draw(tileBitmap->GetBitmap(), tileBitmap->GetBitmapInfo(), tileTransform->WorldPos());
	Renderer2::Get()->Draw(tileBitmap->GetBitmap(), tileBitmap->GetBitmapInfo(), tileTransform->WorldPos());
}
