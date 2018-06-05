#include "player.h"
#include <Renderer2D.h>
#include <Input.h>
#include <Texture.h>
#include "Bullet.h"
#include <exception>
#include <iostream>
player::player()
{
	try
	{
		m_player = new aie::Texture("../bin/textures/ship.png");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	m_playerPosX = 100.0f;
	m_playerPosY = 100.0f;
	m_playerSpeed = 200.0f;

	m_bulletAmount = 20;
	
	for (int i = 0; i < m_bulletAmount; ++i)
	{
		m_vecBullet.push_back(new Bullet(m_playerPosX, m_playerPosY));
	}
	
	m_bulletShoot = false;
}


player::~player()
{
	delete m_player;
}

void player::update(float deltaTime, aie::Input * input)
{
	//Movement
	if (input->isKeyDown(aie::INPUT_KEY_A) && m_playerPosX >= 40)
	{
		m_playerPosX -= m_playerSpeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D) && m_playerPosX <= 1240)
	{
		m_playerPosX += m_playerSpeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_playerPosX >= 40)
	{
		m_playerPosX -= m_playerSpeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_playerPosX <= 1240)
	{
		m_playerPosX += m_playerSpeed * deltaTime;
	}

	//Shooting
	if (m_bulletShoot && input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		for (auto it = m_vecBullet.begin(); it != m_vecBullet.end(); ++it) 
		{
			m_vecBullet.pop_back();
			m_Bulletalive.push_back(new Bullet(m_playerPosX, m_playerPosY));
			break;
		}

			m_bulletShoot = false;
			m_bulletTime = 0.0f;

	}

	//Move bullets
	for (auto it = m_Bulletalive.begin(); it != m_Bulletalive.end(); ++it)
	{
		(*it)->update(deltaTime, input);
		
	}

	//Disable bullets
	if (m_Bulletalive.size() > 19)
	{

		for (auto it = m_Bulletalive.begin(); it != m_Bulletalive.end(); ++it)
		{
			if ((*it)->getPosY() >= 1280)
			{
				m_vecBullet.push_back(new Bullet(m_playerPosX, m_playerPosY));
				m_Bulletalive.pop_back();
			}
			
		}
	}
	m_bulletTime += deltaTime;
	if (m_bulletTime >= .6f)
	{
		m_bulletShoot = true;
	}
	
}

void player::draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_player, m_playerPosX, m_playerPosY);

	for (auto it = m_Bulletalive.begin(); it != m_Bulletalive.end(); ++it)
	{
		(*it)->draw(spriteBatch);
	}
}

float player::getposX()
{
	return m_playerPosX;
}

float player::getposY()
{
	return m_playerPosY;
}

std::vector<Bullet*> player::GetBulletAlive()
{
	return m_Bulletalive;
}


