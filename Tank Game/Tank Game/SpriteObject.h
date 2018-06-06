#pragma once
#include "SceneObject.h"
#include <Texture.h>

class SpriteObject : public SceneObject
{
public:
	SpriteObject();
	SpriteObject(const char* filename);
	virtual ~SpriteObject(); 

	bool load(const char* filename);
	



protected:
	aie::Texture* m_texture;
};

