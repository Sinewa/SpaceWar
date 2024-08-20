#include "DamageComponent.h"

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	DamageComponent::DamageComponent(int hp) : m_iHP(hp) {

	}
	//-----------------------------------------------------------
	void DamageComponent::OnColision(BaseEntity* other) {
		if (--m_iHP <= 0)
		{
			m_pOwner->Destroy();
		}

	}
	//-----------------------------------------------------------
	void DamageComponent::SetHP(int hp) {
		if (hp > -1)
			m_iHP = hp;
	}
	//-----------------------------------------------------------
	int DamageComponent::GetHP() const {
		return m_iHP;
	}
	//-----------------------------------------------------------
}