#include "SpriteComponent.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	SpriteComponent::SpriteComponent() {
		m_sprite = new sf::Sprite();
		m_sprite->setColor(sf::Color::Green);
		m_sprite->setTexture(sf::Texture());
		m_sprite->setTextureRect(sf::IntRect(0, 0, 3, 3));
	}
	//-----------------------------------------------------------
	void SpriteComponent::Init(BaseEntity* owner) {
		Component::Init(owner);
		owner->SetFlags(EntityFlags::EF_VISIBLE);
	}
	//-----------------------------------------------------------
	void SpriteComponent::Update(BaseEntity* owner, float dt) {
		const auto & pos= owner->GetTranslation();
		m_sprite->setPosition(pos.x, pos.y);
	}
	//-----------------------------------------------------------
	void SpriteComponent::GatherDraw(std::vector<sf::Drawable*>& retVal) {
		retVal.push_back(m_sprite);
	}
}