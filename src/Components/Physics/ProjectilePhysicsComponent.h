#pragma once

#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Components/Physics/ShipPhysicsComponent.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseEntity;

	class ProjectilePhysicsComponent : public PhysicsComponent {
	public:

		ProjectilePhysicsComponent(float size, VecF offset) : PhysicsComponent(size, offset) { m_Type = EType::Projectiles; }
		virtual void OnCollision(const PhysicsComponent* other) override {
			if (other->GetType() != EType::Ship && other->GetType() != EType::Projectiles)
				PhysicsComponent::OnCollision(other); 
		}
	};
}