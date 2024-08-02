#pragma once

#include <vector>

namespace SWGame {

	class CoreEntity;

	class Game {
	protected:
		std::vector<CoreEntity*> m_aEntities;
	public:
		void CreateEntity();
		void UpdateEntities(float dt);
	};
}