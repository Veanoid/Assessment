#pragma once
#include <vector>
namespace aie
{
	class Texture;
	class Renderer2D;
	class Input;
}

class Bullet;

class player
{
public:
	player();
	~player();
	void update(float deltaTime, aie::Input* input);
	void draw(aie::Renderer2D* spriteBatch);
	float getposX();
	float getposY();
	std::vector<Bullet*> GetBulletAlive();


private:
	aie::Texture*		m_player;
	float				m_playerPosX;
	float				m_playerPosY;
	float				m_playerSpeed;

	int						m_bulletAmount;
	Bullet*					m_bullets;
	std::vector<Bullet*>	m_vecBullet;
	std::vector<Bullet*>	m_Bulletalive;

	float					m_bulletTime = 0.0f;
	bool					m_bulletShoot;
};


