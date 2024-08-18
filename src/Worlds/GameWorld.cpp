#include "GameWorld.h"

#include "src/Core/Managers/SystemsManager.h"
#include "src/Prefabs/BasePrefab.h"

#include "src/Systems/Physics/PhysicsSystem.h"
#include "src/Systems/Game/AsteroidSystem.h"

namespace SWGame {
	//-----------------------------------------------------------
	void GameWorld::OnInit() {
		World::OnInit();

		AddAndInitSystem(new PhysicsSystem());
		AddAndInitSystem(new AsteroidSystem(40));

	}
	//-----------------------------------------------------------
	void GameWorld::Load() {
		World::Load();

		AddEntity(SWPrefabs::CreateShip(this, { 400, 400 }, 0.f));
	}
	//-----------------------------------------------------------

}