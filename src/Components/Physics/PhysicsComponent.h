#pragma once

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseEntity;

	class PhysicsComponent : public Component {

		friend class PhysicsSystem;

	protected:
		float m_Size = 10.f;
		VecF m_Offset;
	public:
		PhysicsComponent(float size, VecF offset);
		virtual ~PhysicsComponent();
		virtual void Init(BaseEntity* owner) override;

		void OnCollision(const PhysicsComponent* other);
	};
}