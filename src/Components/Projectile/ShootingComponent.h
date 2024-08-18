#pragma once 

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class PlayerMovementControllerComponent;

	class ShootingComponent : public Component {
	protected:
		PlayerMovementControllerComponent* m_pPlayerMovement;
		float m_projectileSpeed = 300.f;
		float m_initialVeloctiy = 50.f;
		float m_projectileTimer = 3.f; //seconds
		float m_shootingDelay = 0.1f; 
		float m_shootingDelayOriginal = 0.1;
	public:
		virtual void OnInit(BaseEntity* owner) override;
		virtual void Update(BaseEntity* owner, float dt) override;
	protected:
		VecF GetLocalMuzzlePosition();
		VecF GetWorldMuzzlePosition();
	};
}