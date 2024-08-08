#pragma once

#include <vector>

#include "src/Systems/Base/BaseSystem.h"


namespace SWGame {

	class PhysicsComponent;

	class PhysicsSystem : public BaseSystem {
		std::vector<PhysicsComponent*> m_aPhysicsComps;
	public:

	};
}