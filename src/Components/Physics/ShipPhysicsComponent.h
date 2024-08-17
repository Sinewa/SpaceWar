#pragma once

#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseEntity;

	class ShipPhysicsComponent : public PhysicsComponent {
	public:

		ShipPhysicsComponent(float size, VecF offset) : PhysicsComponent(size, offset) { m_Type = EType::Ship; }
		virtual void OnCollision(const PhysicsComponent* other) override {
			if (other->GetType() == EType::Asteroid)
				PhysicsComponent::OnCollision(other);
		}
	};
}