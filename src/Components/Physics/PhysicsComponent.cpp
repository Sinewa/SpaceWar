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
	void PhysicsComponent::OnInit(BaseEntity* owner){
		Component::OnInit(owner);

		auto* phySys = owner->GetWorld()->GetSystems()->FindSystem<PhysicsSystem>();
		if (phySys)
			phySys->Register(this);
	}
	//-----------------------------------------------------------
	void PhysicsComponent::OnDelete(BaseEntity* owner) {
		Component::OnDelete(owner);

		auto* phySys = owner->GetWorld()->GetSystems()->FindSystem<PhysicsSystem>();
		if (phySys)
			phySys->UnRegister(this);
	}
	//-----------------------------------------------------------
	void PhysicsComponent::OnCollision(const PhysicsComponent* other) {
		if (m_indestructible)
			return;
		m_pOwner->SetFlags(EntityFlags::EF_DELETE);
		//m_pOwner->ClearFlag(EntityFlags::EF_ACTIVE);
	}
	//-----------------------------------------------------------
	EType PhysicsComponent::GetType() const {
		return m_Type;
	}
	//-----------------------------------------------------------
	void PhysicsComponent::SetImmune(bool immune) {
		m_indestructible = immune;
	}
	//-----------------------------------------------------------
	void PhysicsComponent::SetScale(float size) {
		m_Scale = size;

	}
	//-----------------------------------------------------------
	float PhysicsComponent::GetSize() const {
		return m_Size * m_Scale;
	}
	//-----------------------------------------------------------
}