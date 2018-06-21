#pragma once
#include "GameObject.h"
class IBehaviour
{
public:
	virtual void update(float deltaTiem, GameObject* agent) = 0;
};