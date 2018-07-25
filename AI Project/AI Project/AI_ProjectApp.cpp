#include "AI_ProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateMachine.h"
#include "Graph.h"

AI_ProjectApp::AI_ProjectApp() {

}

AI_ProjectApp::~AI_ProjectApp() {

}

bool AI_ProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_playerStateMachine = new StateMachine();
	m_enemySM = new StateMachine();

	m_graph = new Graph();
	GraphNode* newNode = new GraphNode();
	m_graph->AddNode(newNode);
	m_graph->AddNode(newNode);
	m_graph->AddNode(newNode);
	m_graph->AddNode(newNode);
	m_graph->AddNode(newNode);
	m_graph->AddNode(newNode);
	m_graph->GetNodes()[0]->SetPosition(Vector2 (100, 200));
	m_graph->GetNodes()[1]->SetPosition(Vector2(300, 500));
	m_graph->ConnectNode(m_graph->GetNodes()[0], m_graph->GetNodes()[1], 10);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Agent(new aie::Texture("../bin/textures/ship.png"),Vector2(100, 200));
	m_gaurd = new Agent(new aie::Texture("../bin/textures/car.png"), Vector2(700, 200));
	m_playerStateMachine->ChangeState(m_player, new Evade(m_gaurd));
	m_enemySM->ChangeState(m_gaurd, new Pursuit(m_player));
	m_player->Addbehaviour(m_playerStateMachine);
	m_gaurd->Addbehaviour(m_enemySM);
	return true;
}

void AI_ProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AI_ProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime);
	m_gaurd->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AI_ProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->draw(m_2dRenderer);
	m_gaurd->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}