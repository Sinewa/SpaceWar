#include "RenderManager.h"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

namespace SWGame {
	//-----------------------------------------------------------
	void RenderManager::AppendDrawables(std::vector<sf::Drawable*>& drawables) {
		m_drawables.insert(m_drawables.end(), drawables.begin(), drawables.end());
	}
	//-----------------------------------------------------------
	void RenderManager::Render(sf::RenderTarget* target) {
		
		for (sf::Drawable* drawable : m_drawables) {
			target->draw(*drawable);
		}

		for (sf::Drawable* drawable : m_diagDrawables) {
			target->draw(*drawable);
			delete drawable;
		}

		m_drawables.clear();
		m_diagDrawables.clear();
	}
	//-----------------------------------------------------------
	void RenderManager::AddDiagDrawable(sf::Drawable* diagDrawable) {
		m_diagDrawables.push_back(diagDrawable);
	}
}