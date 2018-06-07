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
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	Vector3 offset = { x, y, 1 };
	return m_texture != nullptr;
	
}

void SpriteObject::onDraw(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globlaTransform);
}


SpriteObject::~SpriteObject()
{
	 delete m_texture; 
}
