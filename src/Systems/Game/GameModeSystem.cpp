#include "GameModeSystem.h"

#include <string>
#include <iostream>

#include <SFML/Graphics/Text.hpp>

#include "src/Systems/UI/TextSystem.h"

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Core/Managers/Visual/FontManager.h"
#include "src/Entities/Game/Ship.h"

#include "src/Components/Game/PlayerDamageComponent.h"
#include "src/Components/Projectile/ShootingComponent.h"

namespace SWGame {
	//-----------------------------------------------------------
	void GameModeSystem::Load() {
		m_UI = GetWorld()->GetSystems()->FindSystem<TextSystem>();

		m_uiHP = m_UI->RegisterText(std::to_string(m_InitPlayerLives), { 50, 700 }, sf::Color::Cyan, 50);
		m_uiLevel = m_UI->RegisterText("Level 0", { 50, 50 }, sf::Color::Cyan, 50);
		m_uiScore = m_UI->RegisterText("0", { 700, 700 }, sf::Color::Cyan, 50);

		m_uiLevelUp = new sf::Text("Level Up!", *Game::GetGame()->GetFontManager()->GetDefaultFont());
		m_uiLevelUp->setOrigin(0, m_uiLevelUp->getCharacterSize());
		m_uiLevelUp->setFillColor(sf::Color::Red);
		m_uiLevelUp->setPosition({ 100, 100 });
		
		
		m_aLevels.push_back({ 0, 10, 10, 1, false });
		for (int i = 1; i < 25; i++) {
			m_aLevels.push_back(m_aLevels[i - 1]);
			
			m_aLevels[i].m_requiredScore += i * 10;
			
			if (!(i % 4))
				m_aLevels[i].m_asteroidMaxSize++;
			
			if (!(i % 5))
				m_aLevels[i].m_bUpgrade = 2;
			else 
				m_aLevels[i].m_bUpgrade = 0;
			
			m_aLevels[i].m_asteroidMaxNum = i * 10 / m_aLevels[i].m_asteroidMaxSize;
			
			m_aLevels[i].m_asteroidSpeed += 5;

		}

		m_UpgradePositions.push_back({ 1, -15 });
		m_UpgradePositions.push_back({ -1, -15 });
		
		m_UpgradePositions.push_back({ 3, -15 });
		m_UpgradePositions.push_back({ -3, -15 });
		
		m_UpgradePositions.push_back({ 5, -15 });
		m_UpgradePositions.push_back({ -5, -15 });

		m_UpgradePositions.push_back({ 10, -15 });
		m_UpgradePositions.push_back({ -10, -15 });

		m_UpgradePositions.push_back({ 15, -15 });
		m_UpgradePositions.push_back({ -15, -15 });

		m_UpgradePositions.push_back({ 1, 10 });
		m_UpgradePositions.push_back({ -1, 10 });
	}
	//-----------------------------------------------------------
	void GameModeSystem::Init(World* world) {
		BaseSystem::Init(world);
	}
	//-----------------------------------------------------------
	void GameModeSystem::OnPlayerDestroyed(Ship* ship) {
		Game::GetGame()->RequestGameState(GameState::EMenu);
		m_Player = nullptr;
	}
	//-----------------------------------------------------------
	void GameModeSystem::OnPlayerHit() {
		if (!m_Player)
			return;
		auto damage = m_Player->FindComponent<PlayerDamageComponent>();
		if (!damage)
			return;

		m_iPlayerLifes = damage->GetHP();
		UpdateUIHP();
		std::cout << "Player Hit! Hp left: " << m_iPlayerLifes << std::endl;
	}
	//-----------------------------------------------------------
	void GameModeSystem::OnAsteroidDestroyed(Asteroid* asteroid) {
		m_iCurrentScore++;
	}
	//-----------------------------------------------------------
	void GameModeSystem::Register(GameModeComponent* comp) {

	}
	//-----------------------------------------------------------
	const Level& GameModeSystem::GetCurrentLevel() const {
		return m_aLevels[m_iCurrentLevel];
	}
	//-----------------------------------------------------------
	const Level& GameModeSystem::GetNextLevel() const {
		return m_aLevels[(m_iCurrentLevel+1) % m_aLevels.size()];
	}
	//-----------------------------------------------------------
	void GameModeSystem::Update(float dt) {
		BaseSystem::Update(dt);

		if (m_bShowingLevelUpUI)
		{
			m_fuiLevelUpTimer -= dt;
			if (m_fuiLevelUpTimer < 0) {
				ShowLevelUpUI(false);
			}
		}
		UpdateUIScore();
		if (HasMetRequirements(GetNextLevel())) {
			if (ProgressLevels()) {
				HealPlayer();

				UpgradePlayer();
				UpdateUI();
				ShowLevelUpUI(true);
			}
		}
	}
	//-----------------------------------------------------------
	void GameModeSystem::UpdateUI() {
		UpdateUIHP();
		UpdateUILevel();
	}
	//-----------------------------------------------------------
	bool GameModeSystem::HasMetRequirements(const Level& level) {
		if (m_iCurrentScore >= level.m_requiredScore)
			return true;
		return false;
	}
	//-----------------------------------------------------------
	bool GameModeSystem::ProgressLevels() {
		if (m_iCurrentLevel < m_aLevels.size() - 1) {
			m_iCurrentLevel++;
			return true;
		}
		return false;
	}
	//-----------------------------------------------------------
	void GameModeSystem::HealPlayer() {
		m_iPlayerLifes++;
		auto damage = m_Player->FindComponent<PlayerDamageComponent>();
		if (!damage)
			return;
		damage->SetHP(m_iPlayerLifes);

	}
	//-----------------------------------------------------------
	void GameModeSystem::ReInit() {
		m_iCurrentScore = 0;
		m_iCurrentLevel = 0;
		m_iPlayerLifes = m_InitPlayerLives;
		m_fuiLevelUpTimer = m_fuiLevelUpTimerDelay;
		m_iPlayerUpgradeLevel = 0;

		UpdateUI();
	}
	//-----------------------------------------------------------
	void GameModeSystem::RegisterPlayer(Ship* player) {
		m_Player = player;
	}
	//-----------------------------------------------------------
	void GameModeSystem::UpgradePlayer() {
		for (int i = 0; i < m_aLevels[m_iCurrentLevel].m_bUpgrade; i++) {
			m_iPlayerUpgradeLevel++;
			auto shootingComp = new ShootingComponent(GetNewMuzzlePos());
			m_Player->AddComponent(shootingComp);
			shootingComp->OnInit(m_Player);
		}
		
	}
	//-----------------------------------------------------------
	void GameModeSystem::ShowLevelUpUI(bool show) {
		if (show) {
			if (!m_bShowingLevelUpUI)
				m_UI->RegisterText(m_uiLevelUp);
			m_fuiLevelUpTimer = m_fuiLevelUpTimerDelay;
			m_bShowingLevelUpUI = true;
		}
		else {
			m_UI->UnRegisterText(m_uiLevelUp);
			m_bShowingLevelUpUI = false;
		}
	}
	//-----------------------------------------------------------
	void GameModeSystem::UpdateUIHP() {

		auto hpString = std::to_string(m_iPlayerLifes);
		m_uiHP->setString(hpString);
	}
	//-----------------------------------------------------------
	void GameModeSystem::UpdateUILevel() {
		std::string text = "Level ";
		text.append(std::to_string(m_iCurrentLevel + 1));
		m_uiLevel->setString(text);
	}
	//-----------------------------------------------------------
	void GameModeSystem::UpdateUIScore() {
		m_uiScore->setString(std::to_string(m_iCurrentScore));
	}
	//-----------------------------------------------------------
	const VecF& GameModeSystem::GetNewMuzzlePos() const {
		return m_UpgradePositions[m_iPlayerUpgradeLevel - 1];
	}
	//-----------------------------------------------------------
}