#include "Game.h"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "src/Core/Managers/InputManager.h"
#include "src/Core/Managers/Visual/RenderManager.h"
#include "src/Core/Managers/Visual/TextureManager.h"
#include "src/Core/World.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	Game::Game() 
		: m_window(new sf::RenderWindow(sf::VideoMode(800, 800), "SpaceWar", sf::Style::Close))
		, m_ActiveWorld(new World())
		, m_renderer(new RenderManager())
		, m_textureManager(new TextureManager())
		, m_inputManager(new InputManager())
	{
		m_inputManager->LoadInputs();
		
	}
	//-----------------------------------------------------------
	Game::~Game() {
		delete m_ActiveWorld;
	}
	//-----------------------------------------------------------
	void Game::Run() {
		float dt = 0;
		sf::Clock clock;

		std::vector<sf::Drawable*> drawables;

		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			dt += clock.restart().asSeconds();
			std::cout << dt << std::endl;
			if (dt < 1 / 120.f)
				continue;

			m_inputManager->HandleInputs();

			m_ActiveWorld->Update(dt);

			drawables.clear();
			m_ActiveWorld->GatherDraw(drawables);
			m_renderer->AppendDrawables(drawables);

			m_window->clear();
			m_renderer->Render(m_window);
			m_window->display();
			dt = 0;
		}
	}
	//-----------------------------------------------------------
	World* Game::GetWorld() const {
		return m_ActiveWorld;
	}
	//-----------------------------------------------------------
	InputManager* Game::GetInputManager() const {
		return m_inputManager;
	}
	//-----------------------------------------------------------
	TextureManager* Game::GetTextureManager() const {
		return m_textureManager;
	}
	//-----------------------------------------------------------
	VecU Game::GetGameAreaSize() const {
		auto size = m_window->getSize();
		return VecU(size.x, size.y);
	}
	//-----------------------------------------------------------
	Game* Game::GetGame() {
		static Game m_Game;
		return &m_Game;
	}
	//-----------------------------------------------------------
}