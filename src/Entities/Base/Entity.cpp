#include "Entity.h"

#include <iostream>

#include "src/Components/Base/Component.h"


namespace SWGame {
	void CoreEntity::Update(float dt) {
		//std::cout << "Updating Entity: " << dt << std::endl;

		for (Component* comp: m_aComponents) {
			comp->Update(this, dt);
		}
	}
	//-----------------------------------------------------------
	bool CoreEntity::IsFlag(EntityFlags flags) const {
		return m_entityFlags.IsSet(flags);
	}
	//-----------------------------------------------------------
	void CoreEntity::SetFlags(EntityFlags flags) {
		m_entityFlags.Set(flags);
	}
	//-----------------------------------------------------------
	void CoreEntity::AddComponent(Component* comp) {
		m_aComponents.push_back(comp);
	}
}