#pragma once

#include <vector>

namespace sf {
	class RenderWindow;
}

namespace SWGame {

	class World;

	class Game {
	protected:
		World* m_ActiveWorld;
		sf::RenderWindow* m_window;
	protected:
		Game();
		virtual ~Game();
	public:

		virtual void Run();

		World* GetWorld() const;


		static Game* GetGame();
	};
}