#pragma once

/// <summary>
/// 프로그램, 씬을 바꿔가며 사용
/// </summary>

class Program
{
public:
	Program();
	~Program();

	void Init();

	void Update();

	void Render();

	void Delete();

	static void ChangeScene(Scene* _scene);
private:
	static Scene* scene;
};
