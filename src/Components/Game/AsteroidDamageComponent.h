#pragma once

#include "src/Components/Game/DamageComponent.h"

namespace SWGame {
	class AsteroidDamageComponent : public DamageComponent {
	public:

		virtual void OnColision(BaseEntity* other) override;
	};
}