#include "GameModeSystem.h"

#include "src/Core/Game.h"
#include "src/Entities/Game/Ship.h"

namespace SWGame {
	//-----------------------------------------------------------
	void GameModeSystem::Load() {
		m_aLevels.push_back({ 0, 10, 10, 1 });
		m_aLevels.push_back({ 10, 15, 20, 1 });
		m_aLevels.push_back({ 30, 15, 30, 2 });
	}
	//-----------------------------------------------------------
	void GameModeSystem::OnPlayerDestroyed(Ship* ship) {
		if (--m_iPlayerLifes) {
			ship->SetFlags(EF_DELETE);
			Game::GetGame()->RequestGameState(GameState::EMenu);
		}
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

		if (HasMetRequirements(GetNextLevel()))
			ProgressLevels();
	}
	//-----------------------------------------------------------
	bool GameModeSystem::HasMetRequirements(const Level& level) {
		if (m_iCurrentScore >= level.m_requiredScore)
			return true;
		return false;
	}
	//-----------------------------------------------------------
	bool GameModeSystem::ProgressLevels() {
		if (m_iCurrentLevel < m_aLevels.size() - 1)
			m_iCurrentLevel++;
	}
	//-----------------------------------------------------------

}