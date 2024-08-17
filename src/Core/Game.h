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

	enum class GameState {
		EInit = 0,
		EMenu,
		EGame		
	};


	class Game {
	protected:
		int m_ActiveWorld;
		sf::RenderWindow* m_window;
		RenderManager* m_renderer;
		TextureManager* m_textureManager;
		InputManager* m_inputManager;
		std::vector<World*> m_registeredWorlds;
		GameState m_GameState;
	protected:
		Game();
		virtual ~Game();
	public:
		virtual void Init();
		virtual void Run();

		World* GetActiveWorld() const;
		InputManager* GetInputManager() const;
		TextureManager* GetTextureManager() const;
		RenderManager* GetRenderer() const;

		VecU GetGameAreaSize() const;
		GameState GetGameState() const;
		
		void RegisterWorld(World* world);

		static Game* GetGame();
	};
}