#include "InitWorld.h"

#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Game/AsteroidSystem.h"
#include "src/Core/Game.h"

namespace SWGame {
	//-----------------------------------------------------------
	void InitWorld::OnInit() {
		World::OnInit();

		m_SystemManager->AddSystem(new AsteroidSystem(100));
	}
	//-----------------------------------------------------------
	void InitWorld::Load() {
		World::Load();
	}
	//-----------------------------------------------------------
	void InitWorld::Update(float dt) {
		World::Update(dt);

		m_fInitTime -= dt;
		if (m_fInitTime < 0) {
			Game::GetGame()->RequestGameState(GameState::EMenu);
		}
	}
	//-----------------------------------------------------------
}