#include "World.h"

#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>

#include "src/Entities/Base/BaseEntity.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Core/Managers/Visual/RenderManager.h"
#include "src/Core/Managers/EntityManager.h"

namespace SWGame {
	World::World() {
		m_SystemManager = new SystemsManager();
		m_EntityManager = new EntityManager();
	}
	//-----------------------------------------------------------
	World::~World() {
		delete m_SystemManager;
		delete m_EntityManager;
	}
	//-----------------------------------------------------------
	void World::Update(float dt) {
		UpdateEntities(dt);
		m_SystemManager->Update(dt);
	}
	//-----------------------------------------------------------
	void World::UpdateEntities(float dt) {
		//std::cout << "Updating World" << std::endl;
		m_EntityManager->UpdateEntities(dt);
	}
	//-----------------------------------------------------------
	void World::GatherDraw(std::vector<sf::Drawable*>& drawables) {
		m_EntityManager->GatherDraw(drawables);
	}
	//-----------------------------------------------------------
	BaseEntity* World::CreateEntity() {
		BaseEntity* newEnt = new BaseEntity();
		return m_EntityManager->AddEntity(newEnt);
	}
	//-----------------------------------------------------------
	BaseEntity* World::AddEntity(BaseEntity* ent) {
		return m_EntityManager->AddEntity(ent);
	}
	//-----------------------------------------------------------
	SystemsManager* World::GetSystems() {
		return m_SystemManager;
	}
	//-----------------------------------------------------------
}