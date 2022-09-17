#include "Framework.h"
#include "Transform.h"

Transform::Transform(float posX, float posY)
{
	position.resize(2);
	position[0] = posX;
	position[1] = posY;

	worldPos.resize(2);
}

void Transform::UpdateWorld()
{
	if (parent)
	{
		worldPos[0] = parent->WorldPos()[0] + position[0];
		worldPos[1] = parent->WorldPos()[1] + position[1];
	}
	else
	{
		worldPos[0] =position[0];
		worldPos[1] =position[1];
	}
}
