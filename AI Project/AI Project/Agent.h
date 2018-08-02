#pragma once
#include <Vector2.h>
#include <vector>
class IBehaviour;
class StateMachine;
namespace aie
{
	class Renderer2D;
	class Texture;
}

class Agent
{
public:
	Agent();
	Agent(aie::Texture* texture, Vector2 pos);

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	void Addbehaviour(IBehaviour* state);
	void AddStateMachine(StateMachine* sm);
	void Addforce(Vector2 force);
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 Getpostion();

	float maxFoce;
	float maxVelocity;

	~Agent();

protected:
	aie::Texture* texture;
	std::vector<IBehaviour*> m_behaviours;
	StateMachine* fsm;
	
};

