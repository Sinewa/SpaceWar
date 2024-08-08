#pragma once

#include "src/Components/Movement/BaseControllerComponent.h"

namespace SWGame {
	class AsteroidControlComponent : public BaseControllerComponent {
		VecF m_VecOfMovement;
	public:
		AsteroidControlComponent(const VecF& movement, float speed);

		virtual void Update(BaseEntity* owner, float dt) override;
	};
}