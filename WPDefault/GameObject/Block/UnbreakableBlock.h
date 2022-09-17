#pragma once

class UnbreakableBlock : public GameObject
{
public:
	UnbreakableBlock();
	~UnbreakableBlock();
	UnbreakableBlock(POINT position);
	// ���� �������� ���� ������
	UnbreakableBlock(POINT position, bool ground);
	UnbreakableBlock(POINT position, int pipeNum);

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	Bitmap* bitmap;

};