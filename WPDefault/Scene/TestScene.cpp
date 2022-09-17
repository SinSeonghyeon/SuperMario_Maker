#include "Framework.h"
#include "TestScene.h"

// 타일의 상태를 가져올 전역변수 + 스위치 케이스 나줘줄 전역 변수
char* g_tileStr = GROUNDBMP;
int g_tileMode = 0;

MushroomBlock* mr_Block;

// 위치를 잡기위한 스냅 그리드 함수
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

	// 바닥 하드 코딩.. y그리드 13고정, y 크기는 대부분 2
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

	// 바닥 없는 배경화면 생성
	a = new Bitmap(IDB_BITMAP6);
	/*
	b = new Bitmap(IDB_Cursor);

	b->SetParent(a);
	b->position = { 50.0f,400.0f };
	*/

	// 맵에디터용 초기화
	// 타일 커서
	m_tile = new Tile(GROUNDBMP);
	m_tile->SetPosition(-1, -1);

	// 전체 타일 배열 크기
	tilesX = MAP_SIZE_X / TILE_SIZE;
	tilesY = WINDOW_SIZE_Y / TILE_SIZE;
	// 현재 타일 배열 위치
	tempX = 0;
	tempY = 0;
	// 돌면서 타일 배열 초기화
	for (int i = 0; i < tilesY; i++)
	{
		for (int j = 0; j < tilesX; j++)
		{
			tiles[i][j] = nullptr;
		}
	}
	
	// 첫 화면에 보여질 타일 초기화 => 하드코딩..
	/*
	// 땅 타일 생성
	
	for (int i = 0; i < 31; i++)
	{
		tiles[13][i] = new UnbreakableBlock(GridToPixel(i, 13), true);
		tiles[14][i] = new UnbreakableBlock(GridToPixel(i, 14), true);
	}	
	*/
	// 블록 타일 생성
	tiles[9][20] = new BreakableBlock(GridToPixel(20, 9));
	tiles[9][21] = new MushroomBlock(GridToPixel(21, 9));
	tiles[9][22] = new BreakableBlock(GridToPixel(22, 9));
	tiles[9][23] = new CoinBlock(GridToPixel(23, 9));
	tiles[9][24] = new BreakableBlock(GridToPixel(24, 9));

	/*
	tiles[11][28] = new UnbreakableBlock(GridToPixel(28, 11), 0);
	tiles[11][29] = new UnbreakableBlock(GridToPixel(29, 11), 1);
	tiles[12][28] = new UnbreakableBlock(GridToPixel(28, 12), 2);	// 파이프타일 생성
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
	

	// 맵 에디터용 업데이트
	POINT mouseXY;
	// 클릭시, 그릴 타일 업데이트
	if (KEYBOARD->Down(VK_LBUTTON))
	{
		// 마우스의 위치를 가져와서
		GetCursorPos(&mouseXY);
		ScreenToClient(Renderer2::Get()->GetHWnd(), &mouseXY);
		if (mouseXY.x < 0 || mouseXY.x > WINDOW_SIZE_X || mouseXY.y < 0 || mouseXY.y > WINDOW_SIZE_Y)
		{
			return;
		}
		// 그리드로 바꿔줌 => 그리드는 Tiles배열의 위치
		// 배열의 X를 카메라의 위치로 잡아줌.
		tempX = int((mouseXY.x) + Renderer2::Get()->GetCamera()->position[0]) / TILE_SIZE;
		tempY = int((mouseXY.y) + Renderer2::Get()->GetCamera()->position[1]) / TILE_SIZE;
		// 맵 범위를 벗어난 부분은 그려주지 않도록 하기
		if (tempX < 0 || tempX > (MAP_SIZE_X / TILE_SIZE) || tempY < 3 || tempY > (WINDOW_SIZE_Y) / TILE_SIZE)
		{
			return;
		}
		// 그 위치의 타일이 nullptr이면 새 타일 생성
		// 0 - 부서지는 블록, 1 - 지우개, 2 - 안부서지는 블록
		// 3 - 코인 물음표, 4 - fake코인블록, 5 - mushroomBlock
		if (tiles[tempY][tempX] == nullptr)
		{
			// 타일 모드에 따라
			switch (g_tileMode)
			{				
				case 0:
				{
					// 땅
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]), true);;
					break;
				}
				case 1:
				{
					// 지우개s
					// 아무일도 없음
					break;
				}
				case 2:
				{
					// 부서지는 블록
					tiles[tempY][tempX] = new BreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 3:
				{
					// 안 부서지는 블록
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 4:
				{
					// fake 코인 블록
					tiles[tempY][tempX] = new FakeCoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 5:
				{
					// 코인나오는 물음표 블록
					tiles[tempY][tempX] = new CoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 6:
				{
					// 코인나오는 물음표 블록
					tiles[tempY][tempX] = new MushroomBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				default:
					break;
			}

		}
		else
		{
			// 타일 모드에 따라
			// 
			delete tiles[tempY][tempX];
			tiles[tempY][tempX] = nullptr;

			switch (g_tileMode)
			{
				// 지워주고 새 타일 생성
				case 0:
				{
					// 땅
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]), true);;
					break;
				}
				case 1:
				{
					// 지우개
					// 아무일 없음 => 위에서 지워주기 때문
					break;
				}
				case 2:
				{
					// 부서지는 블록
					tiles[tempY][tempX] = new BreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 3:
				{
					// 안 부서지는 블록
					tiles[tempY][tempX] = new UnbreakableBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));;
					break;
				}
				case 4:
				{
					// fake 코인 블록
					tiles[tempY][tempX] = new FakeCoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 5:
				{
					// 코인나오는 물음표 블록
					tiles[tempY][tempX] = new CoinBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				case 6:
				{
					// 코인나오는 물음표 블록
					tiles[tempY][tempX] = new MushroomBlock(SnapGridScene(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]));
					break;
				}
				default:
					break;
			}
		}

		// 모드 확인
		//DebugPrint("타일 모드 : %d\n", g_tileMode);

		// 개수 확인
		//DebugPrint("tiles개수 : %d\n", tileSize());
	}
	// 커서 업데이트
	GetCursorPos(&mouseXY);
	ScreenToClient(Renderer2::Get()->GetHWnd(), &mouseXY);
	// 카메라가 음수면 생기는 문제가 있으나.. 고치면 오히려 기존의 것이 잘 작동 안하는 문제가 있어서 그대로둠..
		// 어차피 우리는 대부분 왼쪽으로 가기 때문
	m_tile->SetBitmap(g_tileStr);
	m_tile->SetPosition(mouseXY.x + Renderer2::Get()->GetCamera()->position[0], mouseXY.y + Renderer2::Get()->GetCamera()->position[1]);

	m_tile->Update();

	// Nullptr이 아닌 애들을 업데이트

	// 마리오 죽었는지 확인
	// 맨위가 0.0, 윈도우사이즈보다 2타일 더 떨어지면.
	
	// 마리오 움직임 계산 변수
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
		//Sleep 뺴고 바꿔줘야함!
		Sleep(2500);
		// 가능하면 이 때 애들 다 없애줘야..
		GameManager::GetInstance()->m_UIManager.MarioDie();
		// 게임 오브젝트 클리어 되면 됨!!
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
		//Sleep 뺴고 바꿔줘야함!
		Sleep(2500);
		// 가능하면 이 때 애들 다 없애줘야..
		GameManager::GetInstance()->m_UIManager.MarioDie();
		// 게임 오브젝트 클리어 되면 됨!!
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
	// 그리드 관련 렌더
	Renderer2::Get()->DrawGrid();

	// Nullptr이 아닌 애들을 Render
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

	// 땅 렌더
	for (int i = 0; i < 19; i++)
	{
		ground[i]->Render();
	}
	GameManager::GetInstance()->m_MonsterManager.Render();

	mario->Render();
	// 커서 Render => 이건 무조건 맨밑에...
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