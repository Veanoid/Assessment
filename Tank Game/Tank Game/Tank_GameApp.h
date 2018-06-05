#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Tank_GameApp : public aie::Application {
public:

	Tank_GameApp();
	virtual ~Tank_GameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};