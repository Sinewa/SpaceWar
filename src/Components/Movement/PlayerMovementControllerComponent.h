#pragma once 

#include "src/Components/Movement/BaseControllerComponent.h"

namespace SWGame {

	class BaseEntity;

	class PlayerMovementControllerComponent : public BaseControllerComponent {
		
	public:
		virtual void Update(BaseEntity* owner, float dt) override;
	};
}