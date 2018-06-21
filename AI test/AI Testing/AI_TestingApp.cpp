#include "AI_TestingApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameObject.h"
#include "SeekBehavior.h"
AI_TestingApp::AI_TestingApp() {

}

AI_TestingApp::~AI_TestingApp() {

}

bool AI_TestingApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_ship = new GameObject( new aie::Texture("../bin/textures/ship.png"), glm::vec2(100, 200));
	m_enemy = new GameObject( new aie::Texture("../bin/textures/car.png"), glm::vec2(600, 700));
	m_enemy->AddBehaviour(new SeekBehavior(m_ship));

	return true;
}

void AI_TestingApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AI_TestingApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_ship->update(deltaTime);
	m_enemy->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AI_TestingApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_ship->draw(m_2dRenderer);
	m_enemy->draw(m_2dRenderer);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}