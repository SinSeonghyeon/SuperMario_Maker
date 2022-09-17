#pragma once

class GameObject : public Transform
{
public:
	GameObject(string tag = "null", string name = "null");
	virtual ~GameObject();

	void Init();//생성자의 맨 마지막에 Init() 필수! 게임 오브젝트 매니저에 등록하는 것, 등록안하면 트리거, 충돌 처리 안됨

	virtual void Update() = 0;
	virtual void Render() = 0;

	void UpdateWorlds();//todo : 모르겠음... 좀더 생각해봐야함...
	
	bool isView = false;

	POINT screenLT, screenRB;
	//todo: 스크린에서 해당 게임 오브젝트가 어디 그려져 있는지 쓸 좌표, 화면에 들어와 있거나 근처일때 렌더와 업데이트 하기 위함, 필수요소는 아님
	//카메라와 연산하여 만들것
	string name;
	string tag;

	Animator* animator;
	Bitmap* image;
	Collider* collider;
	RigidBody* rigidBody;

protected:
	friend class GameObjectManager;
	vector<class MonoBehavior*> monoBehaviors;//모노 비헤이비어 여기다 등록
	friend class CameraCheck;
	bool isActive;
};