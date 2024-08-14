#include "PhysicsSystem.h"

#include <SFML/Graphics/CircleShape.hpp>

#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Entities/Base/BaseEntity.h"
#include "src/Core/Utils/Transformations.h"

#include "src/Core/Game.h"
#include "src/Core/Managers/InputManager.h"
#include "src/Core/Managers/Visual/RenderManager.h"

namespace SWGame {
	//-----------------------------------------------------------
	void PhysicsSystem::Update(float dt) {
		for (int i = 0; i < m_aPhysicsComps.size(); i++) {
			for (int j = i + 1; j < m_aPhysicsComps.size(); j++) {
				if (CheckCollision(m_aPhysicsComps[i], m_aPhysicsComps[j]))
				{
					m_aPhysicsComps[i]->OnCollision(m_aPhysicsComps[j]);
					m_aPhysicsComps[j]->OnCollision(m_aPhysicsComps[i]);
				}
			}
		}

	}
	//-----------------------------------------------------------
	void PhysicsSystem::OnDiag(float dt) {
		auto input = Game::GetGame()->GetInputManager();
		if (input->IsKeyPressed(InputFlags::DEBUG))
			m_bDebugActive = true;
		if (m_bDebugActive) {
			auto renderer = Game::GetGame()->GetRenderer();
			for (auto& Pcomp : m_aPhysicsComps) {
				auto circle = new sf::CircleShape(Pcomp->m_Size);
				auto pos = Pcomp->m_pOwner->GetTranslation() - Pcomp->m_Offset;
				
				circle->setPosition(pos.x, pos.y);
				//circle->setRadius(Pcomp->m_Size);
				circle->setOutlineColor(sf::Color::Green);
				circle->setFillColor(sf::Color::Green);
				renderer->AddDiagDrawable(circle);
			}
		}
	}
	//-----------------------------------------------------------
	void PhysicsSystem::Register(PhysicsComponent* comp) {
		m_aPhysicsComps.push_back(comp);
	}
	//-----------------------------------------------------------
	void PhysicsSystem::UnRegister(PhysicsComponent* comp) {
		for (int i = 0; i < m_aPhysicsComps.size(); i++) {
			if (m_aPhysicsComps[i] == comp) {
				m_aPhysicsComps[i] = *m_aPhysicsComps.rbegin();
				m_aPhysicsComps.pop_back();
				return;
			}
		}
	}
	//-----------------------------------------------------------
	bool PhysicsSystem::CheckCollision(PhysicsComponent* lpc, PhysicsComponent* rpc) {
		auto lpos = lpc->m_pOwner->GetTranslation() - lpc->m_Offset;
		auto rpos = rpc->m_pOwner->GetTranslation() - rpc->m_Offset;

		if ((lpos - rpos).LengthSquared() < (lpc->m_Size + rpc->m_Size) * (lpc->m_Size + rpc->m_Size))
			return true;
		return false;
	}
	//-----------------------------------------------------------
}