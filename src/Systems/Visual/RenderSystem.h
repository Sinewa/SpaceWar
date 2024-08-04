#pragma once

#include <vector>

#include "src/Systems/Base/BaseSystem.h"

namespace sf {
	class Drawable;
	class RenderTarget;
}

namespace SWGame {
	
	class RenderSystem : public BaseSystem {
		std::vector<sf::Drawable*> m_drawables;
	public:
		void Render(sf::RenderTarget* target);
	};
}