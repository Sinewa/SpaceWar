#pragma once

#include <vector>

namespace sf {
	class Drawable;
	class RenderTarget;
}

namespace SWGame {
	
	class RenderManager {
		std::vector<sf::Drawable*> m_drawables;
	public:
		void AppendDrawables(std::vector<sf::Drawable*>& drawables);
		void Render(sf::RenderTarget* target);
	};
}