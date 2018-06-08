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
	m_turret.load("../bin/textures/MegaTurret.png", 0, 1);
	m_tank.addChild(&m_turret);
	m_tank.setPostion(getWindowHeight() / 2.f, getWindowWidth() / 2.f);

	m_velocity = Vector3(0, 0, 0);
	m_acceleration = Vector3(0, 0, 0);
	m_mass = 1000;
	m_forceTotal = Vector3(0, 0, 0);
	m_drag = Vector3(0, 2, 0);
	m_speed = 5;

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
	m_Direction = m_tank.getLocalTransform().axis[1];

	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_tank.rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_tank.rotate(-deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_W)) 
	{

		m_forceTotal = m_Direction * m_speed;



		//if (m_speed < m_topspeed)
		//{
		//	m_speed = m_speed += m_acceleration;
		//	auto velocity = Vector3(0, 0, 0);
		//	velocity = velocity + m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//	m_tank.translate(velocity.m_x, velocity.m_y);
		//}
		//else
		//{
		//	m_speed = m_topspeed;
		//	auto velocity = m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//	m_tank.translate(velocity.m_x, velocity.m_y);
		//}
				
	}
	if (input->isKeyUp(aie::INPUT_KEY_W && aie::INPUT_KEY_S))
	{
		//if (m_speed != 0)
		//{
		//	if (m_speed > 0)
		//	{
		//		m_speed -= m_acceleration;
		//		auto velocity = m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//		m_tank.translate(velocity.m_x, velocity.m_y);
		//	}
		//	if (m_speed < 0)
		//	{
		//		m_speed += m_acceleration;
		//		auto velocity = m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//		m_tank.translate(velocity.m_x, velocity.m_y);
		//	}
		//	if (m_speed <5 && m_speed > -5)
		//	{
		//		m_speed = 0;
		//	}
		//	
		//	
		//	auto velocity = m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//	m_tank.translate(velocity.m_x, velocity.m_y);
		//	
		//}
	}
	if (input->isKeyDown(aie::INPUT_KEY_S)) {



		m_forceTotal = m_Direction* -1.0f * m_speed;





		//if (m_speed > -m_topspeed)
		//{
		//	m_speed -= m_acceleration;
		//	auto velocity = m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//	m_tank.translate(velocity.m_x, velocity.m_y);
		//}
		//else
		//{
		//	m_speed = -m_topspeed;
		//	auto velocity = m_speed * deltaTime * m_tank.getLocalTransform().axis[1];
		//	m_tank.translate(velocity.m_x, velocity.m_y);
		//}
	}




	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_turret.rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_turret.rotate(-deltaTime);
	
	m_forceTotal = m_forceTotal - m_drag;

	m_acceleration = m_forceTotal/* / m_mass*/;
	m_velocity = m_velocity + m_acceleration * deltaTime;

	m_tank.translate(m_velocity.m_x, m_velocity.m_y);
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