#pragma once
#include "IBehavior.h"
class SeekBehavior : public IBehaviour
{
public:
	SeekBehavior();
	SeekBehavior(GameObject* target);// setting the target for an enity 
	~SeekBehavior();

	virtual void update(float deltaTiem, GameObject* agent);// updating in real time for the agent
private:
	GameObject * target;// target

	
	
};

