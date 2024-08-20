#pragma once

#include <vector>

namespace sf {
	class Drawable;
}

namespace SWGame {

	class BaseEntity;

	class EntityManager {
	protected:
		std::vector<BaseEntity*> m_aEntities;

	public:
		void UpdateEntities(float dt);
		void GatherDraw(std::vector<sf::Drawable*>& drawables);
		BaseEntity* AddEntity(BaseEntity* ent);
		void Clear();
	};
}