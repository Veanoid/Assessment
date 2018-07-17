#include "Agent.h"



Agent::Agent()
{
}

Agent::Agent(aie::Texture * texture, Vector2 pos)
{
	this->texture = texture;
	this->position = pos;
	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);

}


Agent::~Agent()
{
	delete texture;
}

void Agent::update(float deltaTime)
{
	Addforce(velocity * -0.15f);
	velocity + acceleration, velocity = acceleration * deltaTime;
	position + velocity, position = velocity * deltaTime;
	acceleration = Vector2(0, 0);
}

void Agent::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(texture, position.m_x, position.m_y);
}

void Agent::Addforce(Vector2 force)
{
	acceleration + force, acceleration = force;
}
