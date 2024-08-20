#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Color.hpp>

#include "src/Systems/Base/BaseSystem.h"
#include "src/Core/Utils/Transformations.h"
#include "src/Core/Utils/Array.h"

namespace sf {
	class Text;
	class Drawable;
}

namespace SWGame {
	
	class TextSystem : public BaseSystem {
	protected:
		Array<sf::Text*> m_texts;
		const sf::Color m_defaultColor = sf::Color(31, 53, 242);
	public:
		virtual void GatherDraw(std::vector<sf::Drawable*>& retVal) override;
		sf::Text* RegisterText(std::string string, const VecF& pos, sf::Color color = sf::Color(31, 53, 242), unsigned int size = 30U);
		void RegisterText(sf::Text* text);

		void UnRegisterText(sf::Text* text);
	};
}