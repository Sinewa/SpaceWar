#pragma once 

#include "src/Core/World.h"

namespace SWGame {
	class GameWorld : public World {
		virtual void Load() override;
	};
}