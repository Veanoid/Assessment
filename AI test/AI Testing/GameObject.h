#pragma once
#include<glm\vec2.hpp>
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
	GameObject(aie::Texture* texture, glm::vec2 pos);
	~GameObject();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	void Addforce(glm::vec2 force);
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;
	void AddBehaviour(IBehaviour* behavior);

	float maxForce;
	float maxVelocity;

private:
	aie::Texture* texture;
	std::vector<IBehaviour*> m_behaviours;
};

