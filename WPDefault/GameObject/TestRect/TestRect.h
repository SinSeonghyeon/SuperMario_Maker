#pragma once

/// <summary>
/// �浹 ����� �Ǵ��� �˻��ϱ� ����
/// </summary>

class TestRect : public GameObject
{
public:
	TestRect();
	~TestRect();
	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;


};