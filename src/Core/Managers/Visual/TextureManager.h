#pragma once

#include <unordered_map>
#include <iostream>
#include <string>

#include <SFML/Graphics/Texture.hpp>

namespace SWGame {
	class TextureManager {
		std::unordered_map<std::string ,sf::Texture*> m_Textures;

	public:
		sf::Texture* GetTexture(std::string file) {
			auto it = m_Textures.find(file);
			if (it != m_Textures.end())
				return it->second;
			
			sf::Texture* tex = new sf::Texture();
			if (!tex->loadFromFile(file)) {
				std::cerr << "Could not load texture: " << file << " from file" << std::endl;
				delete tex;
				return nullptr;
			}

			m_Textures.emplace(file, tex);
			return tex;
		}
	};
}