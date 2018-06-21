#include "GameObject.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "IBehavior.h"

GameObject::GameObject()
{
}

GameObject::GameObject(aie::Texture * texture, glm::vec2 pos)
{
	this->texture = texture;
	this->position = pos;
	velocity = glm::vec2(0, 0);
	acceleration = glm::vec2(0, 0);

}


GameObject::~GameObject()
{
	delete texture;
	for (int i = 0; i < m_behaviours.size(); i++)
	{
		delete m_behaviours[i];
	}

}

void GameObject::update(float deltaTime)
{
	Addforce(velocity * -0.15f);
	velocity += acceleration * deltaTime;
	position += velocity * deltaTime;
	acceleration = glm::vec2(0, 0);

	for ( int i = 0; i < m_behaviours.size(); i++)
	{
		m_behaviours[i]->update(deltaTime, this);
	}
}

void GameObject::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(texture, position.x, position.y);
}

void GameObject::Addforce(glm::vec2 force)
{
	acceleration += force;
}

void GameObject::AddBehaviour(IBehaviour * behavior)
{
	m_behaviours.push_back(behavior);
}
