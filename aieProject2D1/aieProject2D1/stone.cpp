#include "stone.h"
#include <Renderer2D.h>
#include <Input.h>
#include <Texture.h>
#include "aieProject2D1App.h"
#include <iostream>



stone::stone(int xpos, int ypos)
{

	m_tex = new aie::Texture("../bin/textures/rock_large.png");
	m_stonePosX = xpos;
	m_stonePosY = ypos;
	m_alive = true;
}


stone::~stone()
{
	delete m_tex;
}

void stone::update(float delatTime)
{
	static int speed = 200;		//Temp
	m_stonePosY -= speed * delatTime;
}

void stone::draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_tex, m_stonePosX, m_stonePosY);
}

float stone::posX()
{
	return m_stonePosX;
}

float stone::posY()
{
	return m_stonePosY;
}




