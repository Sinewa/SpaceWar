#include "Game.h"

#include <SFML/Graphics.hpp>

#include "src/Core/Managers/Visual/RenderManager.h"
#include "src/Core/Managers/Visual/TextureManager.h"
#include "src/Core/World.h"

namespace SWGame {
	Game::Game() {
		m_window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!", sf::Style::Default);
		m_ActiveWorld = new World();
		m_renderer = new RenderManager();
	}
	//-----------------------------------------------------------
	Game::~Game() {
		delete m_ActiveWorld;
	}
	//-----------------------------------------------------------
	void Game::Run() {
		float dt;
		sf::Clock clock;

		std::vector<sf::Drawable*> drawables;

		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			dt = clock.restart().asSeconds();

			m_ActiveWorld->Update(dt);

			m_ActiveWorld->GatherDraw(drawables);
			m_renderer->AppendDrawables(drawables);

			m_window->clear();
			m_renderer->Render(m_window);
			m_window->display();
		}
	}
	//-----------------------------------------------------------
	World* Game::GetWorld() const {
		return m_ActiveWorld;
	}
	//-----------------------------------------------------------
	Game* Game::GetGame() {
		static Game m_Game;
		return &m_Game;
	}
}