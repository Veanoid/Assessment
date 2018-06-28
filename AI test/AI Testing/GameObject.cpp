#include "GameObject.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "IBehavior.h"

GameObject::GameObject()
{
}

GameObject::GameObject(aie::Texture * texture, Vector2 pos)
{
	this->texture = texture; // setting the texture
	this->position = pos; // setting the postion
	velocity = Vector2(0, 0); // setting the velocity 
	acceleration = Vector2(0, 0); // setting the acceleration

}

// for loop for deleting 
GameObject::~GameObject()
{
	delete texture; // deleting the texture
	for (int i = 0; i < m_behaviours.size(); i++) // going through all behaviours in the list
	{
		delete m_behaviours[i];// deleting the current array 
	}

}
// updating 
void GameObject::update(float deltaTime)
{
	Addforce(velocity * -0.15f); // settign the addforce 
	velocity + acceleration, velocity = acceleration * deltaTime;
	position + velocity, position = velocity * deltaTime;
	acceleration = Vector2(0, 0);

	for ( int i = 0; i < m_behaviours.size(); i++)
	{
		m_behaviours[i]->update(deltaTime, this);
	}
}

void GameObject::draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(texture, position.m_x, position.m_y);
}

void GameObject::Addforce(Vector2 force)
{
	acceleration + force, acceleration = force;
}

void GameObject::AddBehaviour(IBehaviour * behavior)
{
	m_behaviours.push_back(behavior);
}
