#include "GameWorld.h"

#include "src/Core/Managers/SystemsManager.h"
#include "src/Prefabs/BasePrefab.h"

#include "src/Systems/Physics/PhysicsSystem.h"
#include "src/Systems/Game/AsteroidSystem.h"
#include "src/Systems/Game/GameModeSystem.h"
#include "src/Systems/UI/TextSystem.h"

#include "src/Core/Managers/EntityManager.h"

namespace SWGame {
	//-----------------------------------------------------------
	void GameWorld::OnInit() {
		World::OnInit();

		AddAndInitSystem(new PhysicsSystem());
		AddAndInitSystem(new TextSystem());
		AddAndInitSystem(new GameModeSystem());
		AddAndInitSystem(new AsteroidSystem(40));

	}
	//-----------------------------------------------------------
	void GameWorld::ReInit() {
		World::ReInit();

		auto gmSys = m_SystemManager->FindSystem<GameModeSystem>();
		gmSys->ReInit();

		auto asterSys = m_SystemManager->FindSystem<AsteroidSystem>();
		asterSys->ReInit();

		AddEntity(SWPrefabs::CreateShip(this, { 400, 400 }, 0.f));
	}
	//-----------------------------------------------------------
	void GameWorld::DeInit() {
		m_EntityManager->Clear();
	}
	//-----------------------------------------------------------
	void GameWorld::Load() {
		World::Load();

	}
	//-----------------------------------------------------------

}