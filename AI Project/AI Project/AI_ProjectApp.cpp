#include "AI_ProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateMachine.h"
#include "Graph.h"
#include "IdleBehavior.h"
#include "Wander.h"

AI_ProjectApp::AI_ProjectApp() {

}

AI_ProjectApp::~AI_ProjectApp() {

}

bool AI_ProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_playerStateMachine = new StateMachine();
	m_enemySM = new StateMachine();

	m_graph = new Graph();

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			GraphNode* yeet = new GraphNode(); 
			yeet->SetPosition(Vector2(i * 64, j * 64));
			m_graph->AddNode(yeet);
		}
	}

	for (auto x : m_graph->GetNodes()) {
		for (auto y : m_graph->GetNodes()) {
			if (x == y) {
				continue;
			}
			//int xDist = x->GetPosition().m_x - y->GetPosition().m_x; 
			//int yDist = x->GetPosition().m_y - y->GetPosition().m_y;

			Vector2 dist = y->GetPosition() - x->GetPosition();
			float length = dist.magnitude();

			if (length <= 70.0f)
			{
				// connect x and y node
				m_graph->ConnectNode(x, y, length);
			}


		}
	}

	auto startNode = m_graph->GetNodes()[0];
	auto endNode = m_graph->GetNodes()[7];

	std::vector<GraphNode*> path = m_graph->DjikstraSearch(startNode, endNode);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Agent(new aie::Texture("../bin/textures/ship.png"),Vector2(100, 0));
	m_gaurd = new Agent(new aie::Texture("../bin/textures/car.png"), Vector2(700, 700));
	m_playerStateMachine->ChangeState(m_player, new Evade(m_gaurd));
	m_enemySM->ChangeState(m_gaurd, new IdleBehavior(m_player));
	m_player->AddStateMachine(m_playerStateMachine);
	m_gaurd->AddStateMachine(m_enemySM);
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
	m_graph->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}