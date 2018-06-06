#include "SpriteObject.h"



SpriteObject::SpriteObject()
{
}

SpriteObject::SpriteObject(const char * filename)
{
	load(filename);
}

bool SpriteObject::load(const char * filename)
{
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	return m_texture != nullptr;
}


SpriteObject::~SpriteObject()
{
	 delete m_texture; 
}
