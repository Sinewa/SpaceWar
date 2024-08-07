#include "BaseEntity.h"

#include <iostream>

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"


namespace SWGame {
	void BaseEntity::Init() {
		for (Component* comp : m_aComponents) {
			comp->Init(this);
		}
	}
	//-----------------------------------------------------------
	void BaseEntity::Update(float dt) {
		for (Component* comp: m_aComponents) {
			comp->Update(this, dt);
		}
	}
	//-----------------------------------------------------------
	void BaseEntity::GatherDraw(std::vector<sf::Drawable*>& retVal) {
		for (Component* comp : m_aComponents) {
			comp->GatherDraw(retVal);
		}
	}
	//-----------------------------------------------------------
	bool BaseEntity::IsFlag(EntityFlags flags) const {
		return m_entityFlags.IsSet(flags);
	}
	//-----------------------------------------------------------
	void BaseEntity::SetFlags(EntityFlags flags) {
		m_entityFlags.Set(flags);
	}
	//-----------------------------------------------------------
	void BaseEntity::AddComponent(Component* comp) {
		m_aComponents.push_back(comp);
	}
	//----------------------------------------------------------
	void BaseEntity::SetTranslation(const VecF& pos) {
		m_transform.m_position = pos;
	}
	//----------------------------------------------------------
	const VecF& BaseEntity::GetTranslation() const {
		return m_transform.m_position;
	}
	//----------------------------------------------------------
	void BaseEntity::SetTransform(const Transformation& transform) {
		m_transform = transform;
	}
	//----------------------------------------------------------
	const Transformation& BaseEntity::GetTransform() const {
		return m_transform;
	}
	//----------------------------------------------------------
}