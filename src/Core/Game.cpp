#include "Game.h"

#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "src/Core/Managers/InputManager.h"
#include "src/Core/Managers/Visual/RenderManager.h"
#include "src/Core/Managers/Visual/TextureManager.h"
#include "src/Core/Managers/Visual/FontManager.h"
#include "src/Core/World.h"
#include "src/Core/Utils/Transformations.h"

#include "src/Worlds/InitWorld.h"
#include "src/Worlds/GameWorld.h"
#include "src/Worlds/MenuWorld.h"

namespace SWGame {
	Game::Game() 
		: m_window(new sf::RenderWindow(sf::VideoMode(800, 800), "SpaceWar", sf::Style::Close))
		, m_renderer(new RenderManager())
		, m_textureManager(new TextureManager())
		, m_fontManager(new FontManager())
		, m_inputManager(new InputManager())
		, m_GameState(GameState::EUninitialized)
	{
		m_inputManager->LoadInputs();
		
		auto circle = new sf::CircleShape(50.f);
		circle->setOrigin(100.f, 100.f);
		circle->setFillColor(sf::Color::Green);
		m_renderer->AddDiagDrawable(circle);
		m_registeredWorlds.push_back(new World());
	}
	//-----------------------------------------------------------
	Game::~Game() {
		for (World* world : m_registeredWorlds) {
			delete world;
		}
	}
	//-----------------------------------------------------------
	void Game::Init() {
		Load();
	}
	//-----------------------------------------------------------
	void Game::Load() {
		RegisterWorld(new SWGame::InitWorld());
		RegisterWorld(new SWGame::MenuWorld());
		RegisterWorld(new SWGame::GameWorld());
	}
	//-----------------------------------------------------------
	void Game::RegisterWorld(World* world) {
		m_registeredWorlds.push_back(world);
		world->OnInit();
		world->Load();
	}
	//-----------------------------------------------------------
	void Game::Run() {
		float dt = 0;
		sf::Clock clock;

		std::vector<sf::Drawable*> drawables;
		

		std::srand(clock.getElapsedTime().asMicroseconds());
		RequestGameState(GameState::EInit);
		while (m_window->isOpen()) {

			if (m_requestedGameState == GameState::EQuit)
				break;

			sf::Event event;
			while (m_window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			if (!m_window->hasFocus())
				continue;

			dt += clock.restart().asSeconds();
			//std::cout << dt << std::endl;
			if (dt < 1 / 120.f)
				continue;

			if (dt > 1 / 30.f)
				dt = 1 / 30.f;

			HandleWorldChange();
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
	FontManager* Game::GetFontManager() const {
		return m_fontManager;
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
	void Game::RequestGameState(GameState state) {
		m_requestedGameState = state;
	}
	//-----------------------------------------------------------
	void Game::HandleWorldChange() {
		if (m_requestedGameState == m_GameState)
			return;

		m_registeredWorlds[m_GameState]->DeInit();
		m_registeredWorlds[m_requestedGameState]->ReInit();
		
		m_GameState = m_requestedGameState;
	}
	//-----------------------------------------------------------
	Game* Game::GetGame() {
		static Game m_Game;
		return &m_Game;
	}
	//-----------------------------------------------------------
}