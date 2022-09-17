#include "Framework.h"
#include "Test_RigidBodyScene.h"

Test_RigidBodyScene::Test_RigidBodyScene()
{
	bitmap = new Bitmap(101);

	mario = new Mario();

	ub_Block = new UnbreakableBlock();
	ub_Block->position = { 200 , 350 };

	b_Block = new BreakableBlock();
	b_Block->position = { 400 , 350 };

	c_Block = new CoinBlock();
	c_Block->position = { 600 , 350 };

	fc_Block = new FakeCoinBlock();
	fc_Block->position = { 800 , 350 };

	mr_Block = new MushroomBlock();
	mr_Block->position = { 700 , 350 };

	mario->position = { 100,-500 };

	testRect = new TestRect();
	col = new TestCollider({ 0,WINDOW_SIZE_Y - 32 }, { WINDOW_SIZE_X, 32 });

	GameManager::GetInstance()->m_ItemManager.CreateItem(300, 610, EItem::Mushroom);
	GameManager::GetInstance()->m_ItemManager.CreateItem(200, 610, EItem::Star);
	GameManager::GetInstance()->m_ItemManager.CreateItem(100, 610, EItem::lifeMushroom);
	GameManager::GetInstance()->m_ItemManager.CreateItem(500, 610, EItem::Flower);

}

Test_RigidBodyScene::~Test_RigidBodyScene()
{
	delete bitmap;
	delete mario;
	delete testRect;
	delete col;

	delete ub_Block;
	delete b_Block;
	delete c_Block;
	delete fc_Block;
	delete mr_Block;
}

void Test_RigidBodyScene::Update()
{
	Renderer::Get()->GetCamera()->Update();
	testRect->Update();
	GameManager::GetInstance()->m_ParticleManager.Update();
	col->Update();
	bitmap->Update();
	mario->Update();
	GameManager::GetInstance()->m_ItemManager.Update();
	ub_Block->Update();
	b_Block->Update();
	c_Block->Update();
	fc_Block->Update();
	mr_Block->Update();
}

void Test_RigidBodyScene::Render()
{
	//bitmap->Render();
	testRect->Render();
	col->Render();
	mario->Render();
	GameManager::GetInstance()->m_ParticleManager.Render();
	GameManager::GetInstance()->m_ItemManager.Render();
	ub_Block->Render();
	b_Block->Render();
	c_Block->Render();
	fc_Block->Render();
	mr_Block->Render();
}
