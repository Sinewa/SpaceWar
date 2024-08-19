#include "SpriteComponent.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "src/Core/Game.h"
#include "src/Core/Managers/Visual/TextureManager.h"
#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	SpriteComponent::SpriteComponent() {
		m_sprite = new sf::Sprite();
		
		LoadTexture("assets/Ship.png");
	}
	//-----------------------------------------------------------
	SpriteComponent::SpriteComponent(const std::string& fileName) {
		m_sprite = new sf::Sprite();
		LoadTexture(fileName);
	}
	//-----------------------------------------------------------
	void SpriteComponent::OnInit(BaseEntity* owner) {
		Component::OnInit(owner);
		owner->SetFlags(EntityFlags::EF_VISIBLE);
	}
	//-----------------------------------------------------------
	void SpriteComponent::Update(BaseEntity* owner, float dt) {
		const auto& transform= owner->GetTransform();
		const auto& pos = transform.GetPosition();
		m_sprite->setPosition(pos.x, pos.y);
		m_sprite->setRotation(transform.GetRotation());
	}
	//-----------------------------------------------------------
	void SpriteComponent::GatherDraw(std::vector<sf::Drawable*>& retVal) {
		retVal.push_back(m_sprite);
	}
	//-----------------------------------------------------------
	bool SpriteComponent::LoadTexture(const std::string& fileName) {
		if (sf::Texture* tex = Game::GetGame()->GetTextureManager()->GetTexture(fileName)) {
			m_sprite->setTexture(*tex, true);
			m_sprite->setOrigin(tex->getSize().x / 2.f, tex->getSize().y / 2.f);
			return true;
		}
		m_sprite->setTexture(sf::Texture());
		m_sprite->setTextureRect(sf::IntRect(0, 0, 3, 3));
		m_sprite->setOrigin(1.5f, 1.5f);
		m_sprite->setColor(sf::Color::Green);
		return false;
	}
	//-----------------------------------------------------------
	unsigned int SpriteComponent::GetSize() const {
		return m_sprite->getTexture()->getSize().x;
	}
	//-----------------------------------------------------------
	sf::Sprite* SpriteComponent::GetSprite() {
		return m_sprite;
	}
	//-----------------------------------------------------------
	VecF SpriteComponent::GetOrigin() const {
		auto origin = m_sprite->getOrigin();
		return VecF(origin.x, origin.y);
	}
}