#pragma once

#include "Application.h"
#include "Renderer2D.h"


class GameObject;
class AI_TestingApp : public aie::Application {
public:

	AI_TestingApp();
	virtual ~AI_TestingApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	GameObject*			m_ship;
	GameObject*			m_enemy;
};