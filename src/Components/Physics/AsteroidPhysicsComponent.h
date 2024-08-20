#pragma once

#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Components/Physics/ShipPhysicsComponent.h"
#include "src/Core/Utils/Transformations.h"
#include "src/Components/Game/DamageComponent.h"

namespace SWGame {
	class BaseEntity;

	class AsteroidPhysicsComponent : public PhysicsComponent {
	public:

		AsteroidPhysicsComponent(float size, VecF offset) : PhysicsComponent(size, offset) { m_Type = EType::Asteroid; }
		virtual void OnCollision(const PhysicsComponent* other) override {
			if (other->GetType() != EType::Asteroid) {
 				if (auto damage = m_pOwner->FindComponent<DamageComponent>())
					damage->OnColision(other->GetOwner());
			}
		}
	};
}