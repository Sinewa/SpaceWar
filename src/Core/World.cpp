#include "World.h"

#include <iostream>

#include "src/Entities/Base/Entity.h"

namespace SWGame {
	void World::Update(float dt) {
		UpdateEntities(dt);
	}
	//-----------------------------------------------------------
	void World::UpdateEntities(float dt) {
		//std::cout << "Updating World" << std::endl;

		for (CoreEntity* ent : m_aEntities) {
			if (ent->IsFlag(EntityFlags::EF_ACTIVE))
				ent->Update(dt);
		}

	}
	//-----------------------------------------------------------
	CoreEntity* World::CreateEntity() {
		CoreEntity* newEnt = new CoreEntity();
		newEnt->SetFlags(EntityFlags::EF_ACTIVE);
		m_aEntities.push_back(newEnt);
		return newEnt;
	}

}