#include "PlayerMovementControllerComponent.h"

#include "src/Core/Game.h"
#include "src/Core/Managers/InputManager.h"
#include "src/Core/Utils/Transformations.h"
#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------

	void PlayerMovementControllerComponent::Update(BaseEntity* owner, float dt) {
		BaseControllerComponent::Update(owner, dt);

		Transformation transform = owner->GetTransform();
		InputManager* inputs = Game::GetGame()->GetInputManager();
		if (inputs->IsKeyPressed(InputFlags::Up))
			m_vVelocity -= GetFrontVector() * m_fAcceleration * dt;
		else
			m_vVelocity -= GetFrontVector() * m_fConstantAcceleration * dt;
		if (inputs->IsKeyPressed(InputFlags::Down)) {
			m_vVelocity += GetFrontVector() * m_fAcceleration * dt;
			if (m_vVelocity.Length() < 5.f)
				m_vVelocity = { 0, 0 };
		}
		if (inputs->IsKeyPressed(InputFlags::RotateL))
			transform.m_rotation -= m_fRotationSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::RotateR))
			transform.m_rotation += m_fRotationSpeed * dt;

		transform.m_position += m_vVelocity * dt;

		SetTransform(transform);
	}
	//-----------------------------------------------------------
	const VecF& PlayerMovementControllerComponent::GetVelocity() const {
		return m_vVelocity;
	}
	//-----------------------------------------------------------
}