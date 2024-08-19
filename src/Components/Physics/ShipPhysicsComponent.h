#pragma once

#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Core/Utils/Transformations.h"

#include "src/Entities/Game/Ship.h"

namespace SWGame {
	class BaseEntity;

	class ShipPhysicsComponent : public PhysicsComponent {
	public:

		ShipPhysicsComponent(float size, VecF offset) : PhysicsComponent(size, offset) { m_Type = EType::Ship; }
		virtual void OnCollision(const PhysicsComponent* other) override {
			if (other->GetType() == EType::Asteroid){
				dynamic_cast<Ship*>(m_pOwner)->Destroy();
			}
		}
	};
}