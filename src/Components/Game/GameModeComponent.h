#pragma once 

#include "src/Components/Base/Component.h"

namespace SWGame {
	class BaseEntity;

	class GameModeComponent : public Component {
	public :
		virtual void OnInit(BaseEntity* owner) override;
	};
}