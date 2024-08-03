#pragma once
#include <iostream>

#include "src/Components/Base/Component.h"

namespace sf {
	class Texture;
}

namespace SWGame {
	class SpriteComponent : public Component {
		sf::Texture* m_texture;
	public:
		void Test() const {
			std::cout << "Test message" << std::endl;
		}
	};
}