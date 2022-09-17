#pragma once

/// <summary>
/// 충돌 제대로 되는지 검사하기 위함
/// </summary>

class TestRect : public GameObject
{
public:
	TestRect();
	~TestRect();
	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;


};