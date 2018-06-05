#include "aieProject2D1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include <time.h>
#include "player.h"
#include "stone.h"
#include <Windows.h>
#include <ctime>
#include <imgui.h>
#include "Bullet.h"

#include <iostream>

aieProject2D1App::aieProject2D1App() {
	
}

aieProject2D1App::~aieProject2D1App() {

}

bool aieProject2D1App::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new player();
	
	srand(unsigned int(time(nullptr)));
	
	m_stoneAmount = 5;

	m_stonesAreAlive = false;
	m_gameover = false;

	return true;
}

void aieProject2D1App::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_player;
	for (auto it = m_vecStones.begin(); it != m_vecStones.end(); ++it)
	{
		delete (*it);
	}
}

void aieProject2D1App::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	m_player->update(deltaTime, input);

	if (!m_stonesAreAlive)
	{
		bringStone();
		m_stonesAreAlive = true;
	}
	addStone();

	//GUI
	ImGui::Begin("Timer");
	ImGui::Text("Timer: (%.1f)", m_timer);
	ImGui::End();

	//update stones
	if (m_vecStones.size() >= 0)
	{
		for (auto it = m_vecStones.begin(); it != m_vecStones.end(); ++it)
		{
			(*it)->update(deltaTime);
		}
	}

	//Collision
	static float collisionDist = 81.0f;
	//Go through all stones
	if (m_player->GetBulletAlive().size() > 1)
	{
		for (auto it = m_vecStones.begin(); it != m_vecStones.end(); ++it)
		{
			//Check if this stone is within range of player
			if (getDist((*it)->posX(), m_player->getposX(), (*it)->posY(), m_player->getposY()) < collisionDist)
				m_gameover = true;

			for (auto bullet : m_player->GetBulletAlive())
			{
				
				if (getDist((*it)->posX(), bullet->getPosX(), (*it)->posY(), bullet->getPosY()) < collisionDist)
				{
					std::cout << "Stone is Dystored" << std::endl;
				}
			}
		}
	}

	//Game over
	if (m_gameover) {
		std::cout << "Player is dead" << std::endl;
		//Save timer

		//Display best times

		//Quit
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void aieProject2D1App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->draw(m_2dRenderer);

	
	
	if (m_vecStones.size() != 0 && m_stonesAreAlive)
	{
		for (auto it = m_vecStones.begin(); it != m_vecStones.end(); ++it)
		{
			(*it)->draw(m_2dRenderer);
		}
	}

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void aieProject2D1App::bringStone()
{
	for (int i = 0; i < m_stoneAmount; ++i)
	{
		m_vecStones.push_back(new stone(rand() % 1280, 720));
	}
}

void aieProject2D1App::addStone()
{
	if (m_vecStones.size() > 0)
	{
		for (auto it = m_vecStones.begin(); it != m_vecStones.end(); ++it)
		{
			if ((*it)->posY() < 0)
			{
				delete (*it);
				//--m_morestone;
				m_vecStones.clear();
				++m_stoneAmount;
			}
			if (m_vecStones.size() == 0)
			{
				m_stonesAreAlive = false;
				break;
			}
		}
	}
}

float aieProject2D1App::getDist(int x1, int x2, int y1, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



