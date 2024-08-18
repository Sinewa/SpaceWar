#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Color.hpp>

#include "src/Systems/Base/BaseSystem.h"
#include "src/Core/Utils/Transformations.h"

namespace sf {
	class Text;
	class Drawable;
}

namespace SWGame {
	
	class TextSystem : public BaseSystem {
	protected:
		std::vector<sf::Text*> m_texts;
		const sf::Color m_defaultColor = sf::Color(31, 53, 242);
	public:
		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal) override;
		void RegisterPermanentText(std::string string, const VecF& pos, sf::Color color = sf::Color(31, 53, 242), unsigned int size = 30U);
		void RegisterText(sf::Text* text);
	};
}