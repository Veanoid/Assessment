#pragma once
#include <vector>
namespace aie
{
	class Texture;
	class Renderer2D;
	class Input;
}

class stone
{
public:
	stone(int xpos, int ypos);
	~stone();
	void update(float delatTime);
	void draw(aie::Renderer2D* spriteBatch);
	float posX();
	float posY();

	void kill() { m_alive = false; }
	bool isAlive() { return m_alive; }

private:
	aie::Texture*		m_tex;
	float				m_stonePosX;
	float				m_stonePosY;
	int					m_windowHeight;
	bool				m_alive;
	
};

