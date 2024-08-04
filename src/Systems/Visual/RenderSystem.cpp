#include "RenderSystem.h"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

namespace SWGame {
	//-----------------------------------------------------------
	void RenderSystem::Render(sf::RenderTarget* target) {
		
		for (sf::Drawable* drawable : m_drawables) {
			target->draw(*drawable);
		}
		
	}
}