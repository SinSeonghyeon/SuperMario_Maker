#include "Framework.h"
#include "TestScene.h"

// Ÿ���� ���¸� ������ �������� + ����ġ ���̽� ������ ���� ����
char* g_tileStr = GROUNDBMP;
int g_tileMode = 0;

MushroomBlock* mr_Block;

// ��ġ�� ������� ���� �׸��� �Լ�
POINT SnapGridScene(long x, long y);
POINT GridToPixel(int gridX, int gridY);

TestScene::TestScene()
{

	GameManager::GetInstance()->m_MonsterManager.CreateMonster(0, 500, 300);
	GameManager::GetInstance()->m_MonsterManager.CreateMonster(0, 300, 300);
	GameManager::GetInstance()->m_MonsterManager.CreateMonster(0, 700, 300);
	GameManager::GetInstance()->m_MonsterManager.CreateMonster(1, 900, 300);
	GameManager::GetInstance()->m_MonsterManager.CreateMonster(1, 1400, 300);


	mario = new Mario();
	//floor = new TestCollider({ 0,WINDOW_SIZE_Y - 32 }, { WINDOW_SIZE_X, 32 });
	//k = new TestCollider({ 500, 300 }, { 32, 32 });

	// �ٴ� �ϵ� �ڵ�.. y�׸��� 13����, y ũ��� ��κ� 2
	ground[0] = new TestCollider(GridToPixel(0, 13), GridToPixel(30, 2));
	ground[1] = new TestCollider(GridToPixel(35, 13), GridToPixel(2, 2));
	ground[2] = new TestCollider(GridToPixel(41, 13), GridToPixel(4, 2));
	ground[3] = new TestCollider(GridToPixel(48, 13), GridToPixel(5, 2));
	ground[4] = new TestCollider(GridToPixel(54, 14), GridToPixel(2, 1));
	ground[5] = new TestCollider(GridToPixel(57, 14), GridToPixel(2, 1));
	ground[6] = new TestCollider(GridToPixel(60, 13), GridToPixel(9, 2));
	ground[7] = new TestCollider(GridToPixel(71, 13), GridToPixel(5, 2));
	ground[8] = new TestCollider(GridToPixel(80, 13), GridToPixel(2, 2));
	ground[9] = new TestCollider(GridToPixel(84, 13), GridToPixel(2, 2));
	ground[10] = new TestCollider(GridToPixel(89, 13), GridToPixel(4, 2));
	ground[11] = new TestCollider(GridToPixel(96, 13), GridToPixel(6, 2));
	ground[12] = new TestCollider(GridToPixel(106, 13), GridToPixel(10, 2));
	ground[13] = new TestCollider(GridToPixel(119, 13), GridToPixel(5, 2));
	ground[14] = new TestCollider(GridToPixel(136, 13), GridToPixel(15, 2));
	ground[15] = new TestCollider(GridToPixel(155, 13), GridToPixel(9, 2));
	ground[16] = new TestCollider(GridToPixel(166, 13), GridToPixel(5, 2));
	ground[17] = new TestCollider(GridToPixel(181, 13), GridToPixel(4, 2));
	ground[18] = new TestCollider(GridToPixel(191, 13), GridToPixel(20, 2));

	// �ٴ� ���� ���ȭ�� ����
	a = new Bitmap(IDB_BITMAP6);
	/*
	b = new Bitmap(IDB_Cursor);

	b->SetParent(a);
	b->position = { 50.0f,400.0f };
	*/

	// �ʿ����Ϳ� �ʱ�ȭ
	// Ÿ�� Ŀ��
	m_tile = new Tile(GROUNDBMP);
	m_tile->SetPosition(-1, -1);

	// ��ü Ÿ�� �迭 ũ��
	tilesX = MAP_SIZE_X / TILE_SIZE;
	tilesY = WINDOW_SIZE_Y / TILE_SIZE;
	// ���� Ÿ�� �迭 ��ġ
	tempX = 0;
	tempY = 0;
	// ���鼭 Ÿ�� �迭 �ʱ�ȭ
	for (int i = 0; i < tilesY; i++)
	{
		for (int j = 0; j < tilesX; j++)
		{
			tiles[i][j] = nullptr;
		}
	}
	
	// ù ȭ�鿡 ������ Ÿ�� �ʱ�ȭ => �ϵ��ڵ�..
	/*
	// �� Ÿ�� ����
	
	for (int i = 0; i < 31; i++)
	{
		tiles[13][i] = new UnbreakableBlock(GridToPixel(i, 13), true);
		tiles[14][i] = new UnbreakableBlock(GridToPixel(i, 14), true);
	}	
	*/
	// ��� Ÿ�� ����
	tiles[9][20] = new BreakableBlock(GridToPixel(20, 9));
	tiles[9][21] = new MushroomBlock(GridToPixel(21, 9));
	tiles[9][22] = new BreakableBlock(GridToPixel(22, 9));
	tiles[9][23] = new CoinBlock(GridToPixel(23, 9));
	tiles[9][24] = new BreakableBlock(GridToPixel(24, 9));

	/*
	tiles[11][28] = new UnbreakableBlock(GridToPixel(28, 11), 0);
	tiles[11][29] = new UnbreakableBlock(GridToPixel(29, 11), 1);
	tiles[12][28] = new UnbreakableBlock(GridToPixel(28, 12), 2);	// ������Ÿ�� ����
	tiles[12][29] = new UnbreakableBlock(GridToPixel(29, 12), 3);
	*/

	GameManager::GetInstance()->m_ItemManager.CreateItem(100, 310, EItem::Coin);
	GameManager::GetInstance()->m_ItemManager.CreateItem(140, 310, EItem::Coin);
	GameManager::GetInstance()->m_ItemManager.CreateItem(180, 310, EItem::Coin);
	GameManager::GetInstance()->m_ItemManager.CreateItem(220, 310, EItem::Coin);
	GameManager::GetInstance()->m_ItemManager.CreateItem(260, 310, EItem::Coin);
	GameManager::GetInstance()->m_ItemManager.CreateItem(300, 310, EItem::Coin);
}

TestScene::~TestScene()
{
	//delete k;
	//delete floor;
	delete mario;
	delete a;
	//delete b;

	for (int i = 0; i < 19; i++)
	{
		delete ground[i];
	}

	delete m_tile;
	for (int i = 0; i < tilesY; i++)
	{
		for (int j = 0; j < tilesX; j++)
		{
			if (tiles != nullptr)
			{
				delete tiles[i][j];
			}
		}
	}
}

void TestScene::Update()
{
	GameManager::GetInstance()->m_MonsterManager.Update();
	GameManager::GetInstance()->m_SoundManager.PlayLoop(SoundTrack::BGM);
	GameManager::GetInstance()->m_ItemManager.Update();
	GameManager::GetInstance()->m_ParticleManager.Update();
	GameManager::GetInstance()->m_UIManager.Update();
	Renderer::Get()->GetCamera()->Update();

		if (abs(Renderer::Get()->GetCamera()->position[0] - mario->position[0]) > 300)
			Renderer::Get()->GetCamera()->position[0] = mario->position[0] - 300;
	

	// �� �����Ϳ� ������Ʈ
	POINT mouseXY;
	// Ŭ����, �׸� Ÿ�� ������Ʈ
	if (KEYBOARD->Down(VK_LBUTTON))
	{
		// ���콺�� ��ġ�� �����ͼ�
		GetCursorPos(&mouseXY);
		ScreenToClient(Renderer2::Get()->GetHWnd(), &mouseXY);
		if (mouseXY.x < 0 || mouseXY.x > WINDOW_SIZE_X || mouseXY.y < 0 || mouseXY.y > WINDOW_SIZE_Y)
		{
			return;
		}
		// �׸���� �ٲ��� => �׸���� Tiles�迭�� ��ġ
		// �迭�� X�� ī�޶��� ��ġ�� �����.
		tempX = int((mouseXY.x) + Renderer2::Get()->GetCamera()->position[0]) / TILE_SIZE;
		tempY = int((mouseXY.y) + Renderer2::Get()->GetCamera()->position[1]) / TILE_SIZE;
		// �� ������ ��� �κ��� �׷����� �ʵ��� �ϱ�
		if (tempX < 0 || tempX > (MAP_SIZE_X / TILE_SIZE) || tempY < 3 || tempY > (WINDOW_SIZE_Y) / TILE_SIZE)
		{
			return;
		}
		// �� ��ġ�� Ÿ���� nullptr�̸� �� Ÿ�� ����
		// 0 - �μ����� ���, 1 - ���찳, 2 - �Ⱥμ����� ���
		// 3 - ���� ����ǥ, 4 - fake���κ��, 5 - mushroomBlock
		if (tiles[tempY][tempX] == nullptr)
		{
			// Ÿ�� ��忡 ����
			switch (g_tileMode)
			{				
				case 0:
				{
					// ��
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]), true);;
					break;
				}
				case 1:
				{
					// ���찳s
					// �ƹ��ϵ� ����
					break;
				}
				case 2:
				{
					// �μ����� ���
					tiles[tempY][tempX] = new BreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 3:
				{
					// �� �μ����� ���
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 4:
				{
					// fake ���� ���
					tiles[tempY][tempX] = new FakeCoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 5:
				{
					// ���γ����� ����ǥ ���
					tiles[tempY][tempX] = new CoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 6:
				{
					// ���γ����� ����ǥ ���
					tiles[tempY][tempX] = new MushroomBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				default:
					break;
			}

		}
		else
		{
			// Ÿ�� ��忡 ����
			// 
			delete tiles[tempY][tempX];
			tiles[tempY][tempX] = nullptr;

			switch (g_tileMode)
			{
				// �����ְ� �� Ÿ�� ����
				case 0:
				{
					// ��
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]), true);;
					break;
				}
				case 1:
				{
					// ���찳
					// �ƹ��� ���� => ������ �����ֱ� ����
					break;
				}
				case 2:
				{
					// �μ����� ���
					tiles[tempY][tempX] = new BreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 3:
				{
					// �� �μ����� ���
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 4:
				{
					// fake ���� ���
					tiles[tempY][tempX] = new FakeCoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 5:
				{
					// ���γ����� ����ǥ ���
					tiles[tempY][tempX] = new CoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 6:
				{
					// ���γ����� ����ǥ ���
					tiles[tempY][tempX] = new MushroomBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				default:
					break;
			}
		}

		// ��� Ȯ��
		//DebugPrint("Ÿ�� ��� : %d\n", g_tileMode);

		// ���� Ȯ��
		//DebugPrint("tiles���� : %d\n", tileSize());
	}
	// Ŀ�� ������Ʈ
	GetCursorPos(&mouseXY);
	ScreenToClient(Renderer2::Get()->GetHWnd(), &mouseXY);
	// ī�޶� ������ ����� ������ ������.. ��ġ�� ������ ������ ���� �� �۵� ���ϴ� ������ �־ �״�ε�..
		// ������ �츮�� ��κ� �������� ���� ����
	m_tile->SetBitmap(g_tileStr);
	m_tile->SetPosition(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]);

	m_tile->Update();

	// Nullptr�� �ƴ� �ֵ��� ������Ʈ

	// ������ �׾����� Ȯ��
	// ������ 0.0, ������������ 2Ÿ�� �� ��������.
	
	// ������ ������ ��� ����
	static int marioDistance = int(mario->position[0] / TILE_SIZE);
	if (int(mario->position[0] / TILE_SIZE) > marioDistance)
	{
		GameManager::GetInstance()->m_Score += 100;
		marioDistance = mario->position[0] / TILE_SIZE;
	}

	if (mario->position[1] > WINDOW_SIZE_Y + 10 || !mario->Life)
	{
		GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::die);
		mario->position[1] = -1000000;
		marioDistance = 1;
		//Sleep ���� �ٲ������!
		Sleep(2500);
		// �����ϸ� �� �� �ֵ� �� �������..
		GameManager::GetInstance()->m_UIManager.MarioDie();
		// ���� ������Ʈ Ŭ���� �Ǹ� ��!!
		GameManager::GetInstance()->m_MonsterManager.DeleteMonsert();
		GameManager::GetInstance()->m_ItemManager.DeleteItem();
		GOM->Clear();
		GameManager::GetInstance()->m_ItemManager.ItemManager::InitItem();
		Program::ChangeScene(new GameoverScene());
	}
	
	if (mario->position[0] > MAP_SIZE_X - (12 * TILE_SIZE))
	{
		GameManager::GetInstance()->m_SoundManager.Playsound(SoundTrack::flagpole);
		mario->position[1] = -1000000;
		marioDistance = 1;
		//Sleep ���� �ٲ������!
		Sleep(2500);
		// �����ϸ� �� �� �ֵ� �� �������..
		GameManager::GetInstance()->m_UIManager.MarioDie();
		// ���� ������Ʈ Ŭ���� �Ǹ� ��!!
		GameManager::GetInstance()->m_MonsterManager.DeleteMonsert();
		GameManager::GetInstance()->m_ItemManager.DeleteItem();
		GOM->Clear();
		GameManager::GetInstance()->m_ItemManager.ItemManager::InitItem();
		Program::ChangeScene(new ClearScene());
	}

	static float _Time = 0;
	if (_Time >= 5.0f)
	{
		GameManager::GetInstance()->m_MonsterManager.CreateMonster(0, RENDERER2->GetCamera()->position[0]+200, 100);
		GameManager::GetInstance()->m_MonsterManager.CreateMonster(1, RENDERER2->GetCamera()->position[0]+700, -400);
		GameManager::GetInstance()->m_ItemManager.CreateItem(RENDERER2->GetCamera()->position[0]+WINDOW_SIZE_X, 300,EItem::Coin);
		_Time = 0;
	}
	_Time += TIME->Delta();

}

void TestScene::Render()
{
	a->Render();
	// �׸��� ���� ����
	Renderer2::Get()->DrawGrid();

	// Nullptr�� �ƴ� �ֵ��� Render
	for (int i = 0; i < tilesY; i++)
	{
		for (int j = 0; j < tilesX; j++)
		{
			if (tiles[i][j] != nullptr)
			{
				tiles[i][j]->Render();
			}
		}
	}

	//b->Render();

	GameManager::GetInstance()->m_ItemManager.Render();
	GameManager::GetInstance()->m_ParticleManager.Render();
	GameManager::GetInstance()->m_UIManager.Render();
	//k->Render();

	//floor->Render();

	// �� ����
	for (int i = 0; i < 19; i++)
	{
		ground[i]->Render();
	}
	GameManager::GetInstance()->m_MonsterManager.Render();

	mario->Render();
	// Ŀ�� Render => �̰� ������ �ǹؿ�...
	POINT mouseXY;
	GetCursorPos(&mouseXY);
	ScreenToClient(Renderer2::Get()->GetHWnd(), &mouseXY);
	if (mouseXY.x < 0 || mouseXY.x > WINDOW_SIZE_X || mouseXY.y < 0 || mouseXY.y > WINDOW_SIZE_Y)
	{
		return;
	}
	else
	{
		m_tile->Render();
	}
}

/*
int TestScene::tileSize()
{
	int count = 0;
	for (int i = 0; i < tilesY; i++)
	{
		for (int j = 0; j < tilesX; j++)
		{
			if (tiles[i][j] != nullptr)
			{
				count++;
			}
		}
	}
	return count;
}
*/

POINT SnapGridScene(long x, long y)
{
	POINT result;
	long mouseX = x / TILE_SIZE;
	long mouseY = y / TILE_SIZE;

	mouseX = mouseX * TILE_SIZE;
	mouseY = mouseY * TILE_SIZE;

	result.x = mouseX;
	result.y = mouseY;

	return result;
}

POINT GridToPixel(int gridX, int gridY)
{
	POINT result;
	result.x = gridX * TILE_SIZE;
	result.y = gridY * TILE_SIZE;

	return result;
}