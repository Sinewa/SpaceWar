#include "Projectile.h"

namespace SWGame {
	//-----------------------------------------------------------
	Projectile::Projectile(float timer) 
	: m_Timer(timer)
	{
	}
	//-----------------------------------------------------------
	void Projectile::Update(float dt) {
		BaseEntity::Update(dt);

		m_Timer -= dt;

		if (m_Timer < 0) {
			SetFlags(EF_DELETE);
		}
	}
	//-----------------------------------------------------------
}