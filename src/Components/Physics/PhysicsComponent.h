#pragma once

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseEntity;

	enum class EType {
		Undef = 0,
		Ship,
		Projectiles,
		Asteroid
	};

	class PhysicsComponent : public Component {

		friend class PhysicsSystem;

	protected:
		float m_Size = 10.f;
		VecF m_Offset;
		EType m_Type = EType::Undef;
		bool m_indestructible = false;
	public:
		PhysicsComponent(float size, VecF offset);
		virtual ~PhysicsComponent();
		virtual void Init(BaseEntity* owner) override;
		virtual void OnDelete(BaseEntity* owner) override;
		EType GetType() const;
		virtual void OnCollision(const PhysicsComponent* other);
		void SetImmune(bool immune);
	};
}