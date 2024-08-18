#include "TextSystem.h"

#include <SFML/Graphics/Text.hpp>

#include "src/Core/Game.h"
#include "src/Core/Managers/Visual/FontManager.h"

namespace SWGame {
	//-----------------------------------------------------------
	void TextSystem::GatherDraw(std::vector<sf::Drawable*>& retVal) {
		for (sf::Text* text : m_texts) {
			retVal.push_back(text);
		}
	}
	//-----------------------------------------------------------
	void TextSystem::RegisterPermanentText(std::string string, const VecF& pos, sf::Color color, unsigned int size) {
		sf::Text* text = new sf::Text(sf::String(string), *Game::GetGame()->GetFontManager()->GetDefaultFont(), size);
		text->setPosition(pos.x, pos.y);
		text->setOrigin(0, size / 2.f);
		text->setFillColor(color);
		m_texts.push_back(text);
	}
	//-----------------------------------------------------------
	void TextSystem::RegisterText(sf::Text* text) {
		m_texts.push_back(text);
	}
	//-----------------------------------------------------------
}
