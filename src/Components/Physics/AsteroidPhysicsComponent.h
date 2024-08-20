#pragma once

#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Components/Physics/ShipPhysicsComponent.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseEntity;

	class AsteroidPhysicsComponent : public PhysicsComponent {
	public:

		AsteroidPhysicsComponent(float size, VecF offset) : PhysicsComponent(size, offset) { m_Type = EType::Asteroid; }
		virtual void OnCollision(const PhysicsComponent* other) override {
			if (other->GetType() != EType::Asteroid) {
				static_cast<Asteroid*>(m_pOwner)->OnHit();
				PhysicsComponent::OnCollision(other);
			}
		}
	};
}