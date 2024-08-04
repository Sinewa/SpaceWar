#pragma once

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class BaseEntity;
	class SystemsManager;
	class RenderManager;

	class World {
	protected:
		std::vector<BaseEntity*> m_aEntities;
		SystemsManager* m_SystemManager;
		
	public:
		World();
		~World();

		BaseEntity* CreateEntity();
		virtual void Update(float dt);
		void GatherDraw(std::vector<sf::Drawable*>& drawables);
		SystemsManager* GetSystems();
	protected:
		void UpdateEntities(float dt);
	};
}