#include "BaseSystem.h"

namespace SWGame {
	//-----------------------------------------------------------
	void BaseSystem::Init(World* world) {
		m_pWorld = world;
	}

	//-----------------------------------------------------------
	void BaseSystem::Update(float dt) {

	}
	//-----------------------------------------------------------
	World* BaseSystem::GetWorld() const {
		return m_pWorld;
	}
}