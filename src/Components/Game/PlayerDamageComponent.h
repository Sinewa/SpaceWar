#pragma once

#include "src/Components/Game/DamageComponent.h"

namespace SWGame {

	class GameModeSystem;
	class PlayerDamageComponent : public DamageComponent {
	protected:

		GameModeSystem* m_gmSys;
	public:
		virtual void OnInit(BaseEntity* owner) override;
		virtual void OnDelete(BaseEntity* owner) override;
		virtual void OnColision(BaseEntity* other) override;
	};
}