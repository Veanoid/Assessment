#include "Bullet.h"
#include <Renderer2D.h>
#include <Input.h>
#include <Texture.h>

Bullet::Bullet( )
{

}


Bullet::Bullet(float playerPosX, float playerPosY)
{
	m_bullet = new aie::Texture("../bin/textures/bullet.png");
	m_posX = playerPosX;
	m_posY = playerPosY + 35;
	m_alive = false;
}


Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime, aie::Input * input)
{
	m_posY += 200.0f * deltaTime;
}

void Bullet::draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_bullet, m_posX, m_posY);
}

void Bullet::start(float posx, float posy)
{
	m_alive = true;
	m_posX = posx;
	m_posY = posy;
}
