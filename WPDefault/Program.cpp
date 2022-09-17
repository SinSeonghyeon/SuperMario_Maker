#include "Framework.h"
#include "Scene/ColliderTestScene.h"
#include "Scene/Test_RigidBodyScene.h"
#include "Scene/Test_MarioScene.h"
#include "Scene/TestSpriteScene.h"
#include "Scene/GameoverScene.h"

Scene* Program::scene = nullptr;

Program::Program()
{
	Init();
}

Program::~Program()
{
	Delete();
}

void Program::Init()
{

	scene = new IntroScene();
	//scene = new TestScene();
	//scene = new ColliderTestScene();
	//scene = new Test_RigidBodyScene();
	//scene = new Test_RigidBodyScene();
	//scene = new TestMapMakerScene();
	//scene = new Test_RigidBodyScene();	//scene = new Test_MarioScene();
	//scene = new TestSpriteScene();
}

void Program::Update()
{
	
	
	GOM->Update();
	Renderer2::Get()->GetCamera()->position[0] = Renderer::Get()->GetCamera()->position[0] + WINDOW_SIZE_X;
	Renderer2::Get()->GetCamera()->position[1] = Renderer::Get()->GetCamera()->position[1];
	Renderer::Get()->GetCamera()->Update();
	//Renderer2::Get()->GetCamera()->Update();
	scene->Update();

}

void Program::Render()
{
	scene->Render();
}

void Program::Delete()
{
	delete scene;
}


void Program::ChangeScene(Scene* _scene) //EX)ChangeScene(new TestScene());
{
	Scene* Swap = scene;
	scene = _scene;
	delete Swap;
}
