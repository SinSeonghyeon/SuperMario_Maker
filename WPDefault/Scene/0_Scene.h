#pragma once

class Scene
{
public:
	Scene();
	~Scene();

	virtual void Update() = 0;
	virtual void Render() = 0;
};