#include "Asteroid.h"

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Game/AsteroidSystem.h"

namespace SWGame {
	void Asteroid::OnDelete(){
		BaseEntity::OnDelete();

		auto world = Game::GetGame()->GetActiveWorld();
		if (!world)
			return;
		auto sys = world->GetSystems();
		if (!sys)
			return;
		auto asteroidSys = sys->FindSystem<AsteroidSystem>();
		if (!asteroidSys)
			return;
		asteroidSys->UnRegister(this);
	}
}