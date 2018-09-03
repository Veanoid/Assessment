#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Agent.h"
#include "Pursuit.h"
#include "Evade.h"
class StateMachine;
class Graph;
class AI_ProjectApp : public aie::Application {
public:

	AI_ProjectApp();
	virtual ~AI_ProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Agent*				m_Enity;
	Agent*				m_player;
	Agent*				m_gaurd;
	StateMachine*		m_playerStateMachine;
	StateMachine*		m_enemySM;
	Graph*				m_graph;

};