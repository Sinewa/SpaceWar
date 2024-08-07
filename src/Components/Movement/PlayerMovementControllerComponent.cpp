#include "PlayerMovementControllerComponent.h"

#include "src/Core/Utils/Position.h"
#include "src/Entities/Base/BaseEntity.h"
#include "src/Core/Game.h"
#include "src/Core/Managers/InputManager.h"

namespace SWGame {
	//-----------------------------------------------------------

	void PlayerMovementControllerComponent::Update(BaseEntity* owner, float dt) {
		BaseControllerComponent::Update(owner, dt);

		PosF position = owner->GetTranslation();
		InputManager* inputs = Game::GetGame()->GetInputManager();
		if (inputs->IsKeyPressed(InputFlags::Up))
			position.y -= m_fSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::Down))
			position.y += m_fSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::Left))
			position.x -= m_fSpeed * dt;
		if (inputs->IsKeyPressed(InputFlags::Right))
			position.x += m_fSpeed * dt;
		SetTranslation(position);
	}
	//-----------------------------------------------------------
}