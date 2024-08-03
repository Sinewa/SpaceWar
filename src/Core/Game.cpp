#include "Game.h"

#include "src/Core/World.h"

namespace SWGame {
	Game::Game() {
		m_ActiveWorld = new World();
	}
	//-----------------------------------------------------------
	Game::~Game() {
		delete m_ActiveWorld;
	}
	//-----------------------------------------------------------
	void Game::Update(float dt) {
		m_ActiveWorld->Update(dt);
	}
	//-----------------------------------------------------------
	World* Game::GetWorld() const {
		return m_ActiveWorld;
	}
	//-----------------------------------------------------------
	Game* Game::GetGame() {
		static Game* m_Game = new Game();
		return m_Game;
	}
}