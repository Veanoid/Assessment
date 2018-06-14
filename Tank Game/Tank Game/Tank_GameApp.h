#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"

class Tank_GameApp : public aie::Application {
public:

	Tank_GameApp();
	virtual ~Tank_GameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void addforce(Vector3 force);
	

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	SpriteObject		m_tank, m_turret;
	Vector3				m_velocity;
	Vector3				m_acceleration;
	Vector3				m_forceTotal;
	Vector3				m_Direction;
	float				m_mass;
	float				m_dragconst;
	Vector3				m_drag;

	float				m_speed;
	//float				m_acceleration = 5.0f;
	//float				m_topspeed = 200;

};