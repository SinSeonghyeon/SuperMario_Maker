#include "Framework.h"
#include "TestSpriteScene.h"

TestSpriteScene::TestSpriteScene()
{
	bitmap = new Bitmap(101);

	unbreakableBlock = new UnbreakableBlock();

	col = new TestCollider({ 0,WINDOW_SIZE_Y - 32 }, { WINDOW_SIZE_X, 32 });
}

TestSpriteScene::~TestSpriteScene()
{
	delete bitmap;
	delete col;
}

void TestSpriteScene::Update()
{
	Renderer::Get()->GetCamera()->Update();

	col->Update();
	//mario->Update();
	
	bitmap->Update();
	unbreakableBlock->Update();
}

void TestSpriteScene::Render()
{
	bitmap->Render();
	col->Render();
	unbreakableBlock->Render();

}
