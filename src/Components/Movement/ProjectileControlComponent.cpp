#include "ProjectileControlComponent.h"

#include "src/Components/Movement/BaseControllerComponent.h"
#include "src/Core/Game.h"
#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	ProjectileControlComponent::ProjectileControlComponent(const VecF& movement, float speed)
			: BaseControllerComponent()
			, m_VecOfMovement(movement) {
			m_fSpeed = speed;
		}
	//-----------------------------------------------------------

	void ProjectileControlComponent::Update(BaseEntity* owner, float dt) {
		BaseControllerComponent::Update(owner, dt);

		Transformation transform = owner->GetTransform();
		transform.m_position = transform.m_position + m_VecOfMovement * m_fSpeed * dt;
		transform.m_rotation = transform.m_rotation + m_fRotationSpeed * dt;

		SetTransform(transform);
	}
	//-----------------------------------------------------------

}