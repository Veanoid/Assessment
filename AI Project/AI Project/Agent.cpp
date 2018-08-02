#include "Agent.h"
#include <Renderer2D.h>
#include"IBehaviour.h"
#include "StateMachine.h"

Agent::Agent()
{
}

Agent::Agent(aie::Texture * texture, Vector2 pos)
{
	this->texture = texture;
	this->position = pos;
	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	fsm = nullptr;

}


Agent::~Agent()
{
	delete texture;
}

void Agent::update(float deltaTime)
{
	Addforce(velocity * -0.15f);
	velocity = velocity + acceleration * deltaTime;
	position = position + velocity * deltaTime;
	acceleration = Vector2(0, 0);

	//if (m_behaviours.size() > 0)
	//	m_behaviours[0]->update(this, deltaTime);

	if (fsm != nullptr)
		fsm->update(this, deltaTime);
}

void Agent::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(texture, position.m_x, position.m_y);
}

void Agent::Addbehaviour(IBehaviour * state)
{
	m_behaviours.push_back(state);
}

void Agent::AddStateMachine(StateMachine * sm)
{
	if (fsm == nullptr)
		fsm = sm;	
}

void Agent::Addforce(Vector2 force)
{
	acceleration = acceleration + force;
}

Vector2 Agent::Getpostion()
{
	return position;
}
