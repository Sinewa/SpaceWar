#pragma once

#include "src/Core/Utils/Transformations.h"

#include "src/Systems/Base/BaseSystem.h"
#include "src/Core/Utils/Array.h"

namespace sf {
	class Text;
}

namespace SWGame {
	class TextSystem;
	class GameModeComponent;
	class Ship;
	class Asteroid;

	struct Level {
		int m_requiredScore = 0;
		int m_asteroidMaxNum = 20;
		float m_asteroidSpeed = 10.f;
		int m_asteroidMaxSize = 1;
		short m_bUpgrade = 0;
	};

	class GameModeSystem : public BaseSystem {
	protected:		
		static constexpr int m_InitPlayerLives = 3;
		Array<Level> m_aLevels;
		int m_iCurrentLevel = 0;
		int m_iCurrentScore = 0;
		int m_iPlayerLifes = m_InitPlayerLives;

		Ship* m_Player;
		TextSystem* m_UI;
		sf::Text* m_uiHP;
		sf::Text* m_uiLevel;
		sf::Text* m_uiScore;

		sf::Text* m_uiLevelUp;
		float m_fuiLevelUpTimerDelay = 3.f;
		float m_fuiLevelUpTimer = 3.f;
		bool m_bShowingLevelUpUI = false;

		int m_iPlayerUpgradeLevel = 0;
		Array<VecF> m_UpgradePositions;
	public:

		void OnPlayerDestroyed(Ship* player);
		void OnPlayerHit();
		void OnAsteroidDestroyed(Asteroid* asteroid);
		void Register(GameModeComponent* comp);
		void RegisterPlayer(Ship* comp);
		const Level& GetCurrentLevel() const;
		const Level& GetNextLevel() const;
		void ReInit();
		
		virtual void Init(World* world) override;
		virtual void Load() override;
		virtual void Update(float dt) override;
	protected:
		bool HasMetRequirements(const Level& level);
		bool ProgressLevels();
		void HealPlayer();
		void UpgradePlayer();
		void UpdateUI();
		void UpdateUIScore();
		void UpdateUILevel();
		void UpdateUIHP();
		void ShowLevelUpUI(bool show);
		const VecF& GetNewMuzzlePos() const;
	};
}