#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
class player;
class stone;
class Bullet;
class aieProject2D1App : public aie::Application {
public:

	aieProject2D1App();
	virtual ~aieProject2D1App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void bringStone();

	void addStone();

	float getDist(int x1, int x2, int y1, int y2);

protected:

	aie::Renderer2D*		m_2dRenderer;
	aie::Font*				m_font;
	player*					m_player;

	stone*					m_stones;
	std::vector<stone*>		m_vecStones;


	Bullet*					m_bullet;

	float					m_timer = 0.0f;
	int						m_stoneAmount;
	bool					m_stonesAreAlive;
	bool					m_gameover;
};