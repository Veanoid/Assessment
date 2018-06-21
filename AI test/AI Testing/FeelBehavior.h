#pragma once
#include "IBehavior.h"
class FeelBehavior : public IBehaviour
{
public:
	FeelBehavior();
	FeelBehavior(GameObject* target);
	~FeelBehavior();

	virtual void update(float deltaTiem, GameObject* agent);
private:
	GameObject * target;
};

