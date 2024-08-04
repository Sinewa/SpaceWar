#pragma once

#include <vector>

namespace sf {
	class RenderTarget;
}

namespace SWGame {
	class BaseEntity;
	class SystemsManager;
	class RenderSystem;

	class World {
	protected:
		std::vector<BaseEntity*> m_aEntities;
		SystemsManager* m_SystemManager;
		RenderSystem* m_Render;
	public:
		World();
		~World();

		BaseEntity* CreateEntity();
		virtual void Update(float dt);
		void Render(sf::RenderTarget* target);
		SystemsManager* GetSystems();
		RenderSystem* GetRenderSystem();
	protected:
		void UpdateEntities(float dt);
	};
}