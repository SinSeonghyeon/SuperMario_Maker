#pragma once

class GameObject;

class GameObjectManager
{
public:
	static GameObjectManager* Get() { return instance; }
	static void Create() { instance = new GameObjectManager(); }
	static void Delete() { delete instance; }

	void Update();

	void CollidePush(Collider* a, Collider* b, Direction dir, int diff);//rigidBody가 Collider 와 충돌했을때 겹치는 부분 밀어주기
	void ClipToFloor(Collider* a, int diff);//중력 미리 계산해서 땅 안뚫고 가게 하기
	void UpdateCollisionInfos();
	void UpdateMonobehaviors();

	void Add(GameObject* gameObject);	//게임에 추가
	void Sub(GameObject* gameObject);	//게임에서 제외

	void Clear();//todo : 모든 관리하는 데이터를 지우는 함수, level이 넘어가거나, 게임이 끝날때 호출 할 예정
private:
	GameObjectManager();
	~GameObjectManager();

	static GameObjectManager* instance;

	set<GameObject*> allGameObjects;//전부
	//두개의 객체에 대한 oldCollide, newCollide를 저장해 EnterTrigger, StayTrigger, ExitTrigger을 구분한다.
	set<GameObject*> allRigidBodies;//rigidBody를 가지고 있는 놈 전부
	//첫번재 GameObject는 RigidBody 있는 놈 전부, 두번째는 그냥 전부
	//첫번째 bool은 예전 충돌 상태, 두번째 bool은 현재 충돌 상태
	map<pair<GameObject*, GameObject*>, pair<bool, bool>> collideManager;

	Collider predictor;//thx to 강상연, 갖고있는 콜라이더가 땅에 닿을지 미리 예측해주는 콜라이더 값복사 해서 쓸 예정

	float fixedTimer;//60프레임하기 위해

	Collider* camRange;//카메라 범위 할 놈

	GameObject* one;
	GameObject* two;
};