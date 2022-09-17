#pragma once

class Transform
{
public:
	Transform(float posX = 0.0f, float posY = 0.0f);

	void UpdateWorld();

	void SetParent(Transform* parent) { this->parent = parent; }

	vector<float> WorldPos() { return worldPos; }

	vector<float> position;//position[0] = x, position[1] = y

private:
	Transform* parent;

	vector<float> worldPos;//·»´õ¿ë º¯¼ö

};  