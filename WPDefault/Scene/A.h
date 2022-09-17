#pragma once

class A : public Scene
{
public:
	A();


	void Play();
	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

private:

};