#pragma once

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	class Projectile : public BaseEntity {
	protected:
		float m_Timer = 0;
	public:
		Projectile(float timer);

		virtual void Update(float dt) override;
	};
}