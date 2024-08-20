#include "AsteroidDamageComponent.h"

#include "src/Entities/Game/Ship.h"

namespace SWGame {
	
	void AsteroidDamageComponent::OnColision(BaseEntity* other) {
		if (dynamic_cast<Ship*>(other)) {
			m_pOwner->Destroy();
		}
		else {
			DamageComponent::OnColision(other);
		}
	}
	
}