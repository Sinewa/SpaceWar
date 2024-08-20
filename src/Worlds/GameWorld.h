#pragma once 

#include "src/Core/World.h"

namespace SWGame {
	class GameWorld : public World {
	public:
		virtual void OnInit() override;
		virtual void ReInit() override;
		virtual void DeInit() override;
		virtual void Load() override;
	};
}