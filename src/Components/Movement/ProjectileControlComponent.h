#pragma once

#include "src/Components/Movement/BaseControllerComponent.h"

namespace SWGame {
	class ProjectileControlComponent : public BaseControllerComponent {
		VecF m_VecOfMovement;
	public:
		ProjectileControlComponent(const VecF& movement, float speed);

		virtual void Update(BaseEntity* owner, float dt) override;
	};
}