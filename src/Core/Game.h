#pragma once

#include <vector>

namespace sf {
	class RenderWindow;
}

namespace SWGame {

	class World;
	class RenderManager;
	class TextureManager;

	class Game {
	protected:
		World* m_ActiveWorld;
		sf::RenderWindow* m_window;
		RenderManager* m_renderer;
		TextureManager* m_textureManager;

	protected:
		Game();
		virtual ~Game();
	public:

		virtual void Run();

		World* GetWorld() const;


		static Game* GetGame();
	};
}