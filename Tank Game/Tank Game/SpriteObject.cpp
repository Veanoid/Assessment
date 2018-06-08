#include "SpriteObject.h"



SpriteObject::SpriteObject()
{
}

SpriteObject::SpriteObject(const char * filename, float x, float y)
{
	load(filename, x, y);
}

bool SpriteObject::load(const char * filename, float x, float y)
{
	Matrix3 m = Matrix3::identity;
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	offset = { x, y, 1 };
	m.data[2][0] = offset.m_x; 
	m.data[2][1] = offset.m_y;
	m_localTransform = m * m_localTransform;
	return m_texture != nullptr;
	
}

void SpriteObject::onDraw(aie::Renderer2D* renderer)
{
	if (offset.m_y == 0)
		renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globlaTransform, 0, 0, 0, 0.5f, 0.5f);
	else
		renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globlaTransform, 0, 0, 0, 0.5f, 0.3f);

}


SpriteObject::~SpriteObject()
{
	 delete m_texture; 
}
