#include "ShootingComponent.h"

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/InputManager.h"
#include "src/Core/Utils/Transformations.h"
#include "src/Entities/Base/BaseEntity.h"

#include "src/Prefabs/BasePrefab.h"

namespace SWGame {
	//-----------------------------------------------------------
	void ShootingComponent::Update(BaseEntity* owner, float dt) {
		Component::Update(owner, dt);

		InputManager* inputs = Game::GetGame()->GetInputManager();
		if (m_shootingDelay < 0 && inputs->IsKeyPressed(InputFlags::Fire))
		{
			m_shootingDelay = m_shootingDelayOriginal;
			auto muzzlePos = GetWorldMuzzlePosition();
			auto ownerPos = m_pOwner->GetTranslation();

			Game::GetGame()->GetWorld()->AddEntity(SWPrefabs::CreateProjectile(muzzlePos, 0, muzzlePos - ownerPos, m_projectileSpeed, m_projectileTimer));
		}
		m_shootingDelay -= dt;
	}
	//-----------------------------------------------------------
	VecF ShootingComponent::GetLocalMuzzlePosition() {
		return { 0, -20 };
	}
	//-----------------------------------------------------------
	VecF ShootingComponent::GetWorldMuzzlePosition() {
		auto ownerTrans= m_pOwner->GetTransform();
		auto muzzleLPos = GetLocalMuzzlePosition();
		
		float sRot = sinf(ToRadians(ownerTrans.m_rotation));
		float cRot = cosf(ToRadians(ownerTrans.m_rotation));

		return VecF{ ownerTrans.m_position.x + cRot * muzzleLPos.x - sRot * muzzleLPos.y, ownerTrans.m_position.y + sRot * muzzleLPos.x + cRot * muzzleLPos.y};
		
	}
	//-----------------------------------------------------------
}