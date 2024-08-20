#include "PlayerDamageComponent.h"

#include "src/Core/World.h"
#include "src/Systems/Game/GameModeSystem.h"
#include "src/Core/Managers/SystemsManager.h"


namespace SWGame {
	//-----------------------------------------------------------
	void PlayerDamageComponent::OnInit(BaseEntity* owner) {
		DamageComponent::OnInit(owner);

		m_gmSys = GetWorld()->GetSystems()->FindSystem<GameModeSystem>();
	}
	//-----------------------------------------------------------
	void PlayerDamageComponent::OnDelete(BaseEntity* owner) {
		DamageComponent::OnDelete(owner);

	}
	//-----------------------------------------------------------
	void PlayerDamageComponent::OnColision(BaseEntity* other) {
		DamageComponent::OnColision(other);
		m_gmSys->OnPlayerHit();
	}
	//-----------------------------------------------------------
}