#pragma once
#include <vector>
#include <assert.h>
#include <Matrix3.h>
#include <Vector3.h>

namespace aie
{
	class Renderer2D;
	class Input;
	class Texture;
}
class SceneObject
{
public:
	SceneObject();
	SceneObject* getParent() const;
	size_t childCount() const;
	SceneObject* getChild(unsigned int index);
	void addChild(SceneObject * child);
	void removeChild(SceneObject * child);
	virtual void onUpdate(float deltaTime);
	virtual void onDraw(aie::Renderer2D * renderer);
	void update(float deltaTime);
	void draw(aie::Renderer2D * renderer);
	const Matrix3 & getLocalTransform() const;
	const Matrix3 & getGlobaTransform() const;
	void updateTransform();
	void setPostion(float x, float y);
	void setRotate(float radians);
	void setScale(float x, float y);
	void translate(float x, float y);
	void rotate(float radians);
	void Scale(float width, float height);
	virtual ~SceneObject();
	

protected:

	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;


	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globlaTransform = Matrix3::identity;

};

