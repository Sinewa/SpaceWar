#include "GameModeComponent.h"


#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Entities/Base/BaseEntity.h"
#include "src/Entities/Game/Ship.h"

#include "src/Systems/Game/GameModeSystem.h"
#include "src/Systems/Game/AsteroidSystem.h"

namespace SWGame {
	//-----------------------------------------------------------
	void GameModeComponent::OnInit(BaseEntity* owner) {
		auto* gmSys = owner->GetWorld()->GetSystems()->FindSystem<GameModeSystem>();
		if (Ship* player = dynamic_cast<Ship*>(owner); gmSys && player)
			gmSys->RegisterPlayer(player);
		
		auto* asteroidSystem = owner->GetWorld()->GetSystems()->FindSystem<AsteroidSystem>();
		if (asteroidSystem)
			asteroidSystem->RegisterShip(owner);
	}
	//-----------------------------------------------------------
	
	//-----------------------------------------------------------
}