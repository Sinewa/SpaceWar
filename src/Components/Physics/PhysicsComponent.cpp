#include "PhysicsComponent.h"

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Physics/PhysicsSystem.h"

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	PhysicsComponent::PhysicsComponent(float size, VecF offset)
		: m_Size(size)
		, m_Offset(offset)
	{
	}
	//-----------------------------------------------------------
	PhysicsComponent::~PhysicsComponent() {
		auto* phySys = Game::GetGame()->GetWorld()->GetSystems()->FindSystem<PhysicsSystem>();
		phySys->UnRegister(this);
	}
	//-----------------------------------------------------------
	void PhysicsComponent::Init(BaseEntity* owner){
		Component::Init(owner);

		auto* phySys = Game::GetGame()->GetWorld()->GetSystems()->FindSystem<PhysicsSystem>();
		phySys->Register(this);
	}
	//-----------------------------------------------------------
	void PhysicsComponent::OnCollision(const PhysicsComponent* other) {
		m_pOwner->SetFlags(EntityFlags::EF_DELETE);
	}
	//-----------------------------------------------------------
}