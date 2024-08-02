#include "Game.h"

#include <iostream>

#include "src/Core/Entity.h"

namespace SWGame {
	void Game::UpdateEntities(float dt) {
		std::cout << "Updating Game" << std::endl;

		for (CoreEntity* ent : m_aEntities) {
			if (ent->IsFlag(EntityFlags::EF_ACTIVE))
				ent->Update(dt);
		}
		
	}
	//-----------------------------------------------------------
	void Game::CreateEntity() {
		CoreEntity* newEnt = new CoreEntity();
		newEnt->SetFlags(EntityFlags::EF_ACTIVE);
		m_aEntities.push_back(newEnt);
	}


}