#include "Ship.h"

#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Game/GameModeSystem.h"

namespace SWGame {
	void Ship::OnDelete() {
		BaseEntity::OnDelete();

	}
	//-----------------------------------------------------------
	void Ship::Destroy() {
		auto gmSys = GetWorld()->GetSystems()->FindSystem<GameModeSystem>();
		if (!gmSys)
			return;

		gmSys->OnPlayerDestroyed(this);
	}
}