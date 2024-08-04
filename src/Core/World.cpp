#include "World.h"

#include <iostream>

#include "src/Entities/Base/BaseEntity.h"
#include "src/Systems/Base/SystemsManager.h"
namespace SWGame {
	World::World() {
		m_SystemManager = new SystemsManager();
	}
	//-----------------------------------------------------------
	World::~World() {
		delete m_SystemManager;
	}
	//-----------------------------------------------------------
	void World::Update(float dt) {
		UpdateEntities(dt);
		m_SystemManager->Update(dt);
	}
	//-----------------------------------------------------------
	void World::UpdateEntities(float dt) {
		//std::cout << "Updating World" << std::endl;

		for (BaseEntity* ent : m_aEntities) {
			if (ent->IsFlag(EntityFlags::EF_ACTIVE))
				ent->Update(dt);
		}
	}
	//-----------------------------------------------------------
	BaseEntity* World::CreateEntity() {
		BaseEntity* newEnt = new BaseEntity();
		newEnt->SetFlags(EntityFlags::EF_ACTIVE);
		m_aEntities.push_back(newEnt);
		return newEnt;
	}
	//-----------------------------------------------------------
	SystemsManager* World::GetSystems() {
		return m_SystemManager;
	}
}