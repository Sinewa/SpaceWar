#include "GameWorld.h"

#include "src/Prefabs/BasePrefab.h"

namespace SWGame {
	//-----------------------------------------------------------
	void GameWorld::Load() {
		World::Load();

		AddEntity(SWPrefabs::CreateShip(this, { 400, 400 }, 0.f));
	}
	//-----------------------------------------------------------

}