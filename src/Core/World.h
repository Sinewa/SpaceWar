#pragma once

#include <vector>

namespace SWGame {
	class BaseEntity;
	class SystemsManager;

	class World {
	protected:
		std::vector<BaseEntity*> m_aEntities;
		SystemsManager* m_SystemManager;
	public:
		World();
		~World();

		BaseEntity* CreateEntity();
		virtual void Update(float dt);

		SystemsManager* GetSystems();

	protected:
		void UpdateEntities(float dt);
	};
}