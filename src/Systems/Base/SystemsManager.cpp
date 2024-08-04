#include "SystemsManager.h"

#include "src/Systems/Base/BaseSystem.h"

namespace SWGame {
	void SystemsManager::Update(float dt)	{
		for (BaseSystem* sys : m_aSystems) {
			sys->Update(dt);
		}
	}
}