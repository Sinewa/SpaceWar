#include "EntityManager.h"

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	void EntityManager::UpdateEntities(float dt) {
		//std::cout << "Updating World" << std::endl;

		for (int i = m_aEntities.size() - 1; i >= 0; --i) {
			if (m_aEntities[i]->IsFlag(EntityFlags::EF_ACTIVE)) {
				m_aEntities[i]->Update(dt);
			}
		}

		for (int i = m_aEntities.size() - 1; i >= 0; --i) {
			if (m_aEntities[i]->IsFlag(EntityFlags::EF_DELETE)) {
				delete m_aEntities[i];
				m_aEntities[i] = m_aEntities[m_aEntities.size() - 1];
				m_aEntities.pop_back();
			}

		}
	}
	//-----------------------------------------------------------
	void EntityManager::GatherDraw(std::vector<sf::Drawable*>& drawables) {
		for (BaseEntity* ent : m_aEntities) {
			if (ent->IsFlag(EntityFlags::EF_ACTIVE) && ent->IsFlag(EntityFlags::EF_VISIBLE))
			{
				ent->GatherDraw(drawables);
			}
		}
	}
	//-----------------------------------------------------------
	BaseEntity* EntityManager::AddEntity(BaseEntity* ent) {
		ent->SetFlags(EntityFlags::EF_ACTIVE);
		m_aEntities.push_back(ent);
		return ent;
	}
	//-----------------------------------------------------------
}