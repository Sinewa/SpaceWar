#include "InitWorld.h"

#include "src/Core/Managers/SystemsManager.h"
#include "src/Core/Managers/InputManager.h"
#include "src/Systems/Game/AsteroidSystem.h"
#include "src/Systems/UI/TextSystem.h"
#include "src/Core/Game.h"

namespace SWGame {
	//-----------------------------------------------------------
	void InitWorld::OnInit() {
		World::OnInit();

		AddAndInitSystem(new AsteroidSystem(100));
		AddAndInitSystem(new TextSystem());

	}
	//-----------------------------------------------------------
	void InitWorld::ReInit() {
		World::ReInit();

	}
	//-----------------------------------------------------------
	void InitWorld::Load() {
		World::Load();

		m_SystemManager->FindSystem<TextSystem>()->RegisterText("SpaceWar the Game", {170, 400}, { 31, 53, 242 });
	}
	//-----------------------------------------------------------
	void InitWorld::Update(float dt) {
		World::Update(dt);

		m_fInitTime -= dt;
		m_fMinInitTime -= dt;
		if (m_fMinInitTime < 0)	{
			auto inMan = Game::GetGame()->GetInputManager();
			if (inMan->IsKeyPressed(InputFlags::Cancel) || inMan->IsKeyPressed(InputFlags::Fire) ){
				m_fInitTime = -1.f;
			}
		}
		if (m_fInitTime < 0) {
			Game::GetGame()->RequestGameState(GameState::EMenu);
		}
	}
	//-----------------------------------------------------------
	
}