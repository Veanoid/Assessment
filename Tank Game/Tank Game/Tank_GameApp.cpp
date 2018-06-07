#include "Tank_GameApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Tank_GameApp::Tank_GameApp() {

}

Tank_GameApp::~Tank_GameApp() {

}

bool Tank_GameApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);


	m_tank.load("../bin/textures/MegaTank.png", 0, 0);
	m_turret.load("../bin/textures/MegaTurret.png", 0, 4);
	m_tank.addChild(&m_turret);
	m_tank.setPostion(getWindowHeight() / 2.f, getWindowWidth() / 2.f);

	return true;
}

void Tank_GameApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Tank_GameApp::update(float deltaTime) {

	

	// input example
	/*aie::Input* input = aie::Input::getInstance();*/
	auto input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_tank.rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_tank.rotate(-deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_W)) {
		auto facing = m_tank.getLocalTransform().axis[1];
		facing = facing * deltaTime * 100;
		m_tank.translate(facing.m_x, facing.m_y);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		auto facing = m_tank.getLocalTransform().axis[1];
		facing = facing * deltaTime * -100;
		m_tank.translate(facing.m_x, facing.m_y );
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_turret.rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_turret.rotate(-deltaTime);

}

void Tank_GameApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_tank.draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}