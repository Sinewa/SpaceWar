#include "Game.h"

#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "src/Core/Managers/InputManager.h"
#include "src/Core/Managers/Visual/RenderManager.h"
#include "src/Core/Managers/Visual/TextureManager.h"
#include "src/Core/World.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	Game::Game() 
		: m_window(new sf::RenderWindow(sf::VideoMode(800, 800), "SpaceWar", sf::Style::Close))
		, m_ActiveWorld(0)
		, m_renderer(new RenderManager())
		, m_textureManager(new TextureManager())
		, m_inputManager(new InputManager())
		, m_GameState(GameState::EInit)
	{
		m_inputManager->LoadInputs();
		
		auto circle = new sf::CircleShape(50.f);
		circle->setOrigin(100.f, 100.f);
		circle->setFillColor(sf::Color::Green);
		m_renderer->AddDiagDrawable(circle);
	}
	//-----------------------------------------------------------
	Game::~Game() {
		for (World* world : m_registeredWorlds) {
			delete world;
		}
	}
	//-----------------------------------------------------------
	void Game::Init() {
	}
	//-----------------------------------------------------------
	void Game::RegisterWorld(World* world) {
		m_registeredWorlds.push_back(world);
	}
	//-----------------------------------------------------------
	void Game::Run() {
		float dt = 0;
		sf::Clock clock;

		std::vector<sf::Drawable*> drawables;
		

		std::srand(clock.getElapsedTime().asMicroseconds());

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

			if (dt > 1 / 30.f)
				dt = 1 / 30.f;

			m_inputManager->HandleInputs();

			GetActiveWorld()->Update(dt);

			drawables.clear();
			GetActiveWorld()->GatherDraw(drawables);
			m_renderer->AppendDrawables(drawables);

			m_window->clear();
			m_renderer->Render(m_window);
			m_window->display();
			dt = 0;
		}
	}
	//-----------------------------------------------------------
	World* Game::GetActiveWorld() const {
		return m_registeredWorlds[m_GameState];
	}
	//-----------------------------------------------------------
	InputManager* Game::GetInputManager() const {
		return m_inputManager;
	}
	//-----------------------------------------------------------
	RenderManager* Game::GetRenderer() const {
		return m_renderer;
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
	GameState Game::GetGameState() const{
		return m_GameState;
	}
	//-----------------------------------------------------------
	void Game::SetGameState(GameState state) {
		m_GameState = state;
	}
	//-----------------------------------------------------------
	Game* Game::GetGame() {
		static Game m_Game;
		return &m_Game;
	}
	//-----------------------------------------------------------
}