#pragma once

class A : public Scene
{
public:
	A();


	void Play();
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

private:

};