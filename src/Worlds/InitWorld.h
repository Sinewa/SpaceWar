#pragma once 

#include "src/Core/World.h"

namespace SWGame {
	class InitWorld : public World {
	protected:
		float m_fInitTime = 10.f;
	public:
		virtual void OnInit() override;
		virtual void Load() override;
		virtual void Update(float dt) override;
	};
}