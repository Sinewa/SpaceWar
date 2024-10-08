#include "SystemsManager.h"

#include "src/Systems/Base/BaseSystem.h"

namespace SWGame {
	void SystemsManager::Update(float dt)	{
		for (BaseSystem* sys : m_aSystems) {
			sys->Update(dt);
		}

		for (BaseSystem* sys : m_aSystems) {
			sys->OnDiag(dt);
		}
	}
	//-----------------------------------------------------------
	void SystemsManager::GatherDraw(std::vector<sf::Drawable*>& retVal) {
		for (BaseSystem* sys : m_aSystems) {
			sys->GatherDraw(retVal);
		}
	}
	//-----------------------------------------------------------
	void SystemsManager::AddSystem(BaseSystem* sys) {
		m_aSystems.push_back(sys);
	}
	//-----------------------------------------------------------
}