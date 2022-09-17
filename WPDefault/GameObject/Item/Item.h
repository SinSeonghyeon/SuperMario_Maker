#pragma once

enum class EItem;
class ItemCheck;
class Item : public GameObject
{
public:
	Item(int _Image, EItem m_case);
	~Item();

	 
	virtual void Update() override;
	virtual void Render() override;
	ItemCheck* m_ItemCheck;
	
	bool isCulling;
};

