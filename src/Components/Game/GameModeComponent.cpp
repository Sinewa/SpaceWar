#include "GameModeComponent.h"


#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Entities/Base/BaseEntity.h"

#include "src/Systems/Game/GameModeSystem.h"

namespace SWGame {
	void GameModeComponent::OnInit(BaseEntity* owner) {
		auto* gmSys = owner->GetWorld()->GetSystems()->FindSystem<GameModeSystem>();
		if (gmSys)
			gmSys->Register(this);
	}
}