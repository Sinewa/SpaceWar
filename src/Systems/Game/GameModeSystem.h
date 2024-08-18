#pragma once

#include "src/Systems/Base/BaseSystem.h"

namespace SWGame {
	class GameModeComponent;

	class GameModeSystem : public BaseSystem {
	public:
		void OnPlayerDestroyed();
		void OnAsteroidDestroyed();
		void Register(GameModeComponent* comp);
	};
}