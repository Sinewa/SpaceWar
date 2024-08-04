#pragma once

#include <vector>

namespace SWGame {
	class CoreEntity;
	class SystemsManager;

	class World {
	protected:
		std::vector<CoreEntity*> m_aEntities;
		SystemsManager* m_SystemManager;
	public:
		World();
		~World();

		CoreEntity* CreateEntity();
		virtual void Update(float dt);

		SystemsManager* GetSystems();

	protected:
		void UpdateEntities(float dt);
	};
}