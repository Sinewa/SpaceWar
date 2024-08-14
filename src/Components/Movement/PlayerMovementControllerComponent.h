#pragma once 

#include "src/Components/Movement/BaseControllerComponent.h"

namespace SWGame {

	class BaseEntity;

	class PlayerMovementControllerComponent : public BaseControllerComponent {
		VecF m_vVelocity;
		float m_fAcceleration = 50.f;
	public:
		virtual void Update(BaseEntity* owner, float dt) override;
		const VecF& GetVelocity() const;
	protected:
		
	};
}