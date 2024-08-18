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

	}
	//-----------------------------------------------------------
	void PhysicsComponent::Init(BaseEntity* owner){
		Component::Init(owner);

		auto* phySys = Game::GetGame()->GetActiveWorld()->GetSystems()->FindSystem<PhysicsSystem>();
		if (phySys)
			phySys->Register(this);
	}
	//-----------------------------------------------------------
	void PhysicsComponent::OnDelete(BaseEntity* owner) {
		Component::OnDelete(owner);

		auto* phySys = Game::GetGame()->GetActiveWorld()->GetSystems()->FindSystem<PhysicsSystem>();
		if (phySys)
			phySys->UnRegister(this);
	}
	//-----------------------------------------------------------
	void PhysicsComponent::OnCollision(const PhysicsComponent* other) {
		
		m_pOwner->SetFlags(EntityFlags::EF_DELETE);
		//m_pOwner->ClearFlag(EntityFlags::EF_ACTIVE);
	}
	//-----------------------------------------------------------
	EType PhysicsComponent::GetType() const {
		return m_Type;
	}
	//-----------------------------------------------------------
}