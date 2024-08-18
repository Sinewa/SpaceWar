#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

#include <SFML/Graphics/Font.hpp>

namespace SWGame {
	class FontManager {
	protected:
		std::unordered_map<std::string, sf::Font*> m_Fonts;
		const char* m_defaultFontName = "assets/Fonts/Angora/Angora-1G3BB.otf";
	public:
		sf::Font* GetDefaultFont() {
			return GetFont(m_defaultFontName);
		}

		sf::Font* GetFont(std::string file) {
			auto it = m_Fonts.find(file);
			if (it != m_Fonts.end())
				return it->second;

			sf::Font* font = new sf::Font();
			if (!font->loadFromFile(file)) {
				std::cerr << "Could not load font: " << file << " from file" << std::endl;
				delete font;
				return nullptr;
			}

			m_Fonts.emplace(file, font);
			return font;
		}
	};
}