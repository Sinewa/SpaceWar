#include "MenuWorld.h"

#include "src/Core/Game.h"
#include "src/Core/Managers/InputManager.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Game/AsteroidSystem.h"
#include "src/Systems/UI/TextSystem.h"
#include "src/Systems/Physics/PhysicsSystem.h"

#include "src/Prefabs/BasePrefab.h"

namespace SWGame {
	//-----------------------------------------------------------
	void MenuWorld::OnInit() {
		World::OnInit();
		AddAndInitSystem(new AsteroidSystem(100));
		AddAndInitSystem(new TextSystem());
		AddAndInitSystem(new PhysicsSystem());

	}
	//-----------------------------------------------------------
	void MenuWorld::ReInit() {
		World::ReInit();

		m_eSelectedEntry = EMenuSelect::Play;
	}
	//-----------------------------------------------------------
	void MenuWorld::Load() {
		auto textSys = m_SystemManager->FindSystem<TextSystem>();
		textSys->RegisterText("SpaceWar the Game", { 170, 50 });
		
		textSys->RegisterText("Play", { 350, 350 });
		//textSys->RegisterText("Score", { 350, 400 });
		textSys->RegisterText("Quit", { 350, 450 });

		m_eSelectedEntry = EMenuSelect::Play;

		m_selector = SWPrefabs::CreateSelector(this, m_selectorPositions[m_eSelectedEntry], 90);
		AddEntity(m_selector);
	}
	//-----------------------------------------------------------
	void MenuWorld::Update(float dt) {
		World::Update(dt);

		auto inMan = Game::GetGame()->GetInputManager();
		if (inMan->WasKeyJustPressed(InputFlags::Down)) {
			m_eSelectedEntry = static_cast<EMenuSelect>((m_eSelectedEntry + 1) % Count);
		}
		else if (inMan->WasKeyJustPressed(InputFlags::Up)) {
			if (m_eSelectedEntry == 0) {
				m_eSelectedEntry = EMenuSelect::Last;
			}
			else {
				m_eSelectedEntry = static_cast<EMenuSelect>((m_eSelectedEntry - 1) % Count);
			}
		}
		else if (inMan->WasKeyJustPressed(InputFlags::Confirm)) {
			HandleConfirmation();
		}


		m_selector->SetTranslation(m_selectorPositions[m_eSelectedEntry]);
	}
	//-----------------------------------------------------------
	void MenuWorld::HandleConfirmation() {
		switch (m_eSelectedEntry)
		{
		case SWGame::MenuWorld::Play: {
			Game::GetGame()->RequestGameState(GameState::EGame);
			break;
		}
		//case SWGame::MenuWorld::Score: {
		//	break;
		//}
		case SWGame::MenuWorld::Exit: {
			Game::GetGame()->RequestGameState(GameState::EQuit);
			break;
		}
		default:
			break;
		}
	}
	//-----------------------------------------------------------

}