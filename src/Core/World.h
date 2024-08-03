#pragma once

#include <vector>

namespace SWGame {
	class CoreEntity;

	class World {
	protected:
		std::vector<CoreEntity*> m_aEntities;
	public:
		CoreEntity* CreateEntity();
		virtual void Update(float dt);
	protected:
		void UpdateEntities(float dt);
	};
}