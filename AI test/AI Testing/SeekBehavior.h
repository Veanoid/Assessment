#pragma once
#include "IBehavior.h"
class SeekBehavior : public IBehaviour
{
public:
	SeekBehavior();
	SeekBehavior(GameObject* target);
	~SeekBehavior();

	virtual void update(float deltaTiem, GameObject* agent);
private:
	GameObject * target;

	
	
};

