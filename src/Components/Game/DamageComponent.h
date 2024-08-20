#pragma once 

#include "src/Components/Base/Component.h"

namespace SWGame {
	class BaseEntity;

	class DamageComponent : public Component {
	protected:
		int m_iHP;
	public:
		DamageComponent(int hp = 3);
		virtual void OnColision(BaseEntity* other);
		void SetHP(int hp);
		int GetHP() const;
	};
}