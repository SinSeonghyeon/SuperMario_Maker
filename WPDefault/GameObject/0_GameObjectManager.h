#pragma once

class GameObject;

class GameObjectManager
{
public:
	static GameObjectManager* Get() { return instance; }
	static void Create() { instance = new GameObjectManager(); }
	static void Delete() { delete instance; }

	void Update();

	void CollidePush(Collider* a, Collider* b, Direction dir, int diff);//rigidBody�� Collider �� �浹������ ��ġ�� �κ� �о��ֱ�
	void ClipToFloor(Collider* a, int diff);//�߷� �̸� ����ؼ� �� �ȶհ� ���� �ϱ�
	void UpdateCollisionInfos();
	void UpdateMonobehaviors();

	void Add(GameObject* gameObject);	//���ӿ� �߰�
	void Sub(GameObject* gameObject);	//���ӿ��� ����

	void Clear();//todo : ��� �����ϴ� �����͸� ����� �Լ�, level�� �Ѿ�ų�, ������ ������ ȣ�� �� ����
private:
	GameObjectManager();
	~GameObjectManager();

	static GameObjectManager* instance;

	set<GameObject*> allGameObjects;//����
	//�ΰ��� ��ü�� ���� oldCollide, newCollide�� ������ EnterTrigger, StayTrigger, ExitTrigger�� �����Ѵ�.
	set<GameObject*> allRigidBodies;//rigidBody�� ������ �ִ� �� ����
	//ù���� GameObject�� RigidBody �ִ� �� ����, �ι�°�� �׳� ����
	//ù��° bool�� ���� �浹 ����, �ι�° bool�� ���� �浹 ����
	map<pair<GameObject*, GameObject*>, pair<bool, bool>> collideManager;

	Collider predictor;//thx to ����, �����ִ� �ݶ��̴��� ���� ������ �̸� �������ִ� �ݶ��̴� ������ �ؼ� �� ����

	float fixedTimer;//60�������ϱ� ����

	Collider* camRange;//ī�޶� ���� �� ��

	GameObject* one;
	GameObject* two;
};