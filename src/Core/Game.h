#pragma once

#include <vector>

#include "src/Core/Utils/Transformations.h"

namespace sf {
	class RenderWindow;
}

namespace SWGame {

	class World;
	class RenderManager;
	class FontManager;
	class TextureManager;
	class InputManager;

	enum GameState {
		EUninitialized = 0,
		EInit,
		EMenu,
		EGame		
	};


	class Game {
	protected:
		//int m_ActiveWorld;
		sf::RenderWindow* m_window;
		RenderManager* m_renderer;
		TextureManager* m_textureManager;
		FontManager* m_fontManager;
		InputManager* m_inputManager;
		std::vector<World*> m_registeredWorlds;
		GameState m_GameState;
		GameState m_requestedGameState;
	protected:
		Game();
		virtual ~Game();

		void HandleWorldChange();
	public:
		virtual void Init();
		virtual void Load();
		virtual void Run();

		World* GetActiveWorld() const;
		InputManager* GetInputManager() const;
		TextureManager* GetTextureManager() const;
		FontManager* GetFontManager() const;
		RenderManager* GetRenderer() const;

		VecU GetGameAreaSize() const;
		GameState GetGameState() const;
		void RequestGameState(GameState state);
		
		void RegisterWorld(World* world);

		static Game* GetGame();
	};
}