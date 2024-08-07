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
			transform.m_position -= GetFrontVector() * m_fSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::Down))
			transform.m_position += GetFrontVector() * m_fSpeed * dt;
		//if (inputs->IsKeyPressed(InputFlags::Left))
		//	transform.m_position.x -= m_fSpeed * dt;
		//if (inputs->IsKeyPressed(InputFlags::Right))
		//	transform.m_position.x += m_fSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::RotateL))
			transform.m_rotation -= m_fRotationSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::RotateR))
			transform.m_rotation += m_fRotationSpeed * dt;

		SetTransform(transform);
	}
	//-----------------------------------------------------------
}