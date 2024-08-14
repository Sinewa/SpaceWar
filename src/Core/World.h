#pragma once

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class BaseEntity;
	class SystemsManager;
	class EntityManager;
	class RenderManager;

	class World {
	protected:
		SystemsManager* m_SystemManager;
		EntityManager* m_EntityManager;
	public:
		World();
		~World();
		void Init();
		BaseEntity* CreateEntity();
		BaseEntity* AddEntity(BaseEntity* ent);
		virtual void Update(float dt);
		void GatherDraw(std::vector<sf::Drawable*>& drawables);
		SystemsManager* GetSystems();
	protected:
		void UpdateEntities(float dt);
	};
}