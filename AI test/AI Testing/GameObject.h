#pragma once
#include <Vector2.h>
#include <vector>
namespace aie
{
	class Renderer2D;
	class Texture;
}
class IBehaviour;
class GameObject
{
public:
	GameObject();
	GameObject(aie::Texture* texture, Vector2 pos); // setting the texture and the postion 
	~GameObject();

	void update(float deltaTime);// updating in deltatime meaning real time 
	void draw(aie::Renderer2D* renderer);// drwaing the sprite onto the computer program 

	void Addforce(Vector2 force); // adding a force using a vector 
	Vector2 position; // using vector to set postions 
	Vector2 velocity;// using a vector to get velocity
	Vector2 acceleration;// using a vector to get acceleration
	void AddBehaviour(IBehaviour* behavior);// adding a behavior to entitys

	float maxForce; // having a max force cap limit
	float maxVelocity;// hvaing a max velocity cap limit

private:
	aie::Texture* texture; // pointing at textures
	std::vector<IBehaviour*> m_behaviours;// adding behaviours to a vector list
};

