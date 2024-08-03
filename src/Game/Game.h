#pragma once

#include <vector>

namespace SWGame {

	class World;

	class Game {
	protected:
		World* m_ActiveWorld;
		
		Game();
	public:
		virtual ~Game();

		virtual void Update(float dt);

		World* GetWorld() const;


		static Game* GetGame();
	};
}