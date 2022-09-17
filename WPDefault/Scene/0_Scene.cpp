#include "Framework.h"
#include "0_Scene.h"

Scene::Scene()
{
	if (Renderer::Get()->GetCamera() != NULL)
	{
		Renderer::Get()->GetCamera()->position[0] = 0;
		Renderer::Get()->GetCamera()->position[1] = 0;
	}
}

Scene::~Scene()
{
}

