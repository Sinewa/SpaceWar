#pragma once

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {
	class BaseEntity;
	class BaseSystem;
	class EntityManager;
	class RenderManager;
	class SystemsManager;

	class World {
	protected:
		SystemsManager* m_SystemManager;
		EntityManager* m_EntityManager;
	public:
		World();
		virtual	~World();
		virtual void OnInit();
		virtual void OnDeInit();
		virtual void Load();
		virtual BaseEntity* CreateEntity();
		virtual BaseEntity* AddEntity(BaseEntity* ent);
		virtual void Update(float dt);
		virtual void GatherDraw(std::vector<sf::Drawable*>& drawables);
		virtual SystemsManager* GetSystems();
	protected:
		virtual void UpdateEntities(float dt);
		void AddAndInitSystem(BaseSystem* sys);

	};
}