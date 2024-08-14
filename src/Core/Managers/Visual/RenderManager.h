#pragma once

#include <vector>

namespace sf {
	class Drawable;
	class RenderTarget;
}

namespace SWGame {
	
	class RenderManager {
		std::vector<sf::Drawable*> m_drawables;
		std::vector<sf::Drawable*> m_diagDrawables;
	public:
		void AppendDrawables(std::vector<sf::Drawable*>& drawables); 
		void AddDiagDrawable(sf::Drawable* diagDrawable);
		void Render(sf::RenderTarget* target);
	};
}