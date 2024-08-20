#include "Component.h"

#include <iostream>

#include <SFML/Graphics/Drawable.hpp>

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	void Component::OnInit(BaseEntity* owner) {
		m_pOwner = owner;
	}
	//-----------------------------------------------------------
	void Component::Update(BaseEntity* owner, float dt) {
		//std::cout << "Updating Component" << std::endl;
	}
	//-----------------------------------------------------------
	void Component::GatherDraw(std::vector<sf::Drawable*>& retVal) {
	}
	//-----------------------------------------------------------
	void Component::OnDelete(BaseEntity* owner) {

	}
	//-----------------------------------------------------------
	World* Component::GetWorld() const {
		return m_pOwner->GetWorld();
	}
	//-----------------------------------------------------------
	BaseEntity* Component::GetOwner() const {
		return m_pOwner;
	}
	//-----------------------------------------------------------
}