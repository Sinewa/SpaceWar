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
		AddAndInitSystem(new AsteroidSystem(100));
		AddAndInitSystem(new TextSystem());
		AddAndInitSystem(new PhysicsSystem());

		World::OnInit();
	}
	//-----------------------------------------------------------
	void MenuWorld::Load() {
		auto textSys = m_SystemManager->FindSystem<TextSystem>();
		textSys->RegisterPermanentText("SpaceWar the Game", { 170, 50 });
		
		textSys->RegisterPermanentText("Play", { 350, 350 });
		textSys->RegisterPermanentText("Score", { 350, 400 });
		textSys->RegisterPermanentText("Quit", { 350, 450 });

		m_eSelectedEntry = EMenuSelect::Play;

		m_selector = SWPrefabs::CreateSelector(this, m_selectorPositions[m_eSelectedEntry], 90);
		AddEntity(m_selector);
	}
	//-----------------------------------------------------------
	void MenuWorld::Update(float dt) {
		World::Update(dt);

		auto inMan = Game::GetGame()->GetInputManager();
		if (inMan->IsKeyPressed(InputFlags::Down)) {
			m_eSelectedEntry = static_cast<EMenuSelect>((m_eSelectedEntry + 1) % 3);
		}

		m_selector->SetTranslation(m_selectorPositions[m_eSelectedEntry]);
	}
}