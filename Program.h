#pragma once

/// <summary>
/// ���α׷�, ���� �ٲ㰡�� ���
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
