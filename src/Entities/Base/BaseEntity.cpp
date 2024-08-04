#include "BaseEntity.h"

#include <iostream>

#include "src/Components/Base/Component.h"


namespace SWGame {
	void BaseEntity::Update(float dt) {
		//std::cout << "Updating Entity: " << dt << std::endl;

		for (Component* comp: m_aComponents) {
			comp->Update(this, dt);
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
}