#pragma once
#include <vector>
#include <assert.h>


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
	virtual ~SceneObject() {
		if (m_parent != nullptr)
			m_parent->removeChild(this);

		for (auto child : m_children)
			child->m_parent = nullptr;
	}
	
	SceneObject* getParent() const { return m_parent; }
	size_t childCount() const { return m_children.size(); }
	SceneObject* getChild(unsigned int index) const {
		return m_children[index];
	}

	void SceneObject::addChild(SceneObject* child) {
		assert(child->m_parent == nullptr);
		child->m_parent = this;
		m_children.push_back(child);
	}

	void SceneObject::removeChild(SceneObject* child) {
		auto iter = std::find(m_children.begin(),
			m_children.end(), child);
		if (iter != m_children.end()) {
			m_children.erase(iter);
			child->m_parent = nullptr;
		}
	}

	virtual void SceneObject::onUpdate(float deltaTime) { }
	virtual void SceneObject::onDraw(aie::Renderer2D* renderer) { }

	void SceneObject::onUpdate(float deltaTime) {
		onUpdate(deltaTime);
		for (auto child : m_children)
			child->update(deltaTime);
	}

	void SceneObject::onDraw(aie::Renderer2D* renderer) {

		onDraw(renderer);

		for (auto child : m_children)
			child->draw(renderer);
	}
protected:

	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;


	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globlaTransform = Matrix3::identity;

};

