#include "Entity.h"

#include <iostream>

#include "src/Core/Component.h"


namespace SWGame {
	void CoreEntity::Update(float dt) {
		std::cout << "Updating Entity" << std::endl;

		for (Component* comp: m_aComponents) {
			comp->Update(dt);
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
}