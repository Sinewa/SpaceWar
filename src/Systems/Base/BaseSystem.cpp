#include "BaseSystem.h"

namespace SWGame {
	//-----------------------------------------------------------
	void BaseSystem::Init(World* world) {
		m_pWorld = world;
	}
	//-----------------------------------------------------------
	World* BaseSystem::GetWorld() const {
		return m_pWorld;
	}
}