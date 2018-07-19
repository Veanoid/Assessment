#pragma once
#include <Vector2.h>
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

	void Addforce(Vector2 force);
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 Getpostion();

	float maxFoce;
	float maxVelocity;

	~Agent();

private:
	aie::Texture* texture;
	
};

