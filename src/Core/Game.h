#pragma once

#include <vector>

#include "src/Core/Utils/Transformations.h"

namespace sf {
	class RenderWindow;
}

namespace SWGame {

	class World;
	class RenderManager;
	class TextureManager;
	class InputManager;

	class Game {
	protected:
		World* m_ActiveWorld;
		sf::RenderWindow* m_window;
		RenderManager* m_renderer;
		TextureManager* m_textureManager;
		InputManager* m_inputManager;

	protected:
		Game();
		virtual ~Game();
	public:

		virtual void Run();

		World* GetWorld() const;
		InputManager* GetInputManager() const;
		TextureManager* GetTextureManager() const;
		RenderManager* GetRenderer() const;

		VecU GetGameAreaSize() const;

		
		static Game* GetGame();
	};
}