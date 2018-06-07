#pragma once
#include "SceneObject.h"
#include <Texture.h>
#include <Renderer2D.h>
#include <Matrix3.h>

class SpriteObject : public SceneObject
{
public:
	SpriteObject();
	SpriteObject(const char* filename, float x, float y);
	virtual ~SpriteObject(); 

	bool load(const char* filename, float x, float y);

	virtual void onDraw(aie::Renderer2D* renderer);
	
	



protected:
	aie::Texture* m_texture = nullptr;
};

