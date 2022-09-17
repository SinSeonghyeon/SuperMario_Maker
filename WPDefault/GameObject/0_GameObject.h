#pragma once

class GameObject : public Transform
{
public:
	GameObject(string tag = "null", string name = "null");
	virtual ~GameObject();

	void Init();//�������� �� �������� Init() �ʼ�! ���� ������Ʈ �Ŵ����� ����ϴ� ��, ��Ͼ��ϸ� Ʈ����, �浹 ó�� �ȵ�

	virtual void Update() = 0;
	virtual void Render() = 0;

	void UpdateWorlds();//todo : �𸣰���... ���� �����غ�����...
	
	bool isView = false;

	POINT screenLT, screenRB;
	//todo: ��ũ������ �ش� ���� ������Ʈ�� ��� �׷��� �ִ��� �� ��ǥ, ȭ�鿡 ���� �ְų� ��ó�϶� ������ ������Ʈ �ϱ� ����, �ʼ���Ҵ� �ƴ�
	//ī�޶�� �����Ͽ� �����
	string name;
	string tag;

	Animator* animator;
	Bitmap* image;
	Collider* collider;
	RigidBody* rigidBody;

protected:
	friend class GameObjectManager;
	vector<class MonoBehavior*> monoBehaviors;//��� �����̺�� ����� ���
	friend class CameraCheck;
	bool isActive;
};