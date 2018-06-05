#pragma once
namespace aie
{
	class Texture;
	class Renderer2D;
	class Input;
}

class Bullet
{
public:
	Bullet();
	Bullet(float playerPosX, float playerPosY);
	~Bullet();

	void update(float deltaTime, aie::Input* input);
	void draw(aie::Renderer2D* spriteBatch);

	void start(float posx, float posy);

	bool isalive() { return m_alive; }
	void kill() { m_alive = false; }
	float getPosY() { return m_posY; }
	float getPosX() { return m_posX; }
	


private:
	aie::Texture*	m_bullet;
	float			m_posX;
	float			m_posY;
	bool			m_alive;

};

