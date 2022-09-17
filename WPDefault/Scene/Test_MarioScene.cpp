#include "Framework.h"
#include "Test_MarioScene.h"

Test_MarioScene::Test_MarioScene()
{
	mario = new Mario();
	floor = new TestCollider({ 0,WINDOW_SIZE_Y - 32 }, { WINDOW_SIZE_X, 32 });
	test = new TestCollider({ 500,500 }, { 32,32 });
}

Test_MarioScene::~Test_MarioScene()
{
	delete test;
	delete floor;
	delete mario;
}

void Test_MarioScene::Update()
{
	test->Update();
	floor->Update();
	mario->Update();
}

void Test_MarioScene::Render()
{
	test->Render();
	floor->Render();
	mario->Render();
}
