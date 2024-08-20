#pragma once

#include "src/Systems/Base/BaseSystem.h"
#include "src/Core/Utils/Array.h"

namespace SWGame {
	class GameModeComponent;
	class Ship;
	class Asteroid;

	struct Level {
		int m_requiredScore = 0;
		float m_asteroidMax = 20.f;
		float m_asteroidSpeed = 10.f;
		int m_asteroidMaxSize = 1;
	};

	class GameModeSystem : public BaseSystem {
	protected:		
		static constexpr int m_InitPlayerLives = 3;
		Array<Level> m_aLevels;
		int m_iCurrentLevel = 0;
		int m_iCurrentScore = 0;
		int m_iPlayerLifes = m_InitPlayerLives;
	public:
		void OnPlayerDestroyed(Ship* player);
		void OnAsteroidDestroyed(Asteroid* asteroid);
		void Register(GameModeComponent* comp);
		const Level& GetCurrentLevel() const;
		const Level& GetNextLevel() const;
		void ReInit();

		virtual void Load() override;
		virtual void Update(float dt) override;
	protected:
		bool HasMetRequirements(const Level& level);
		bool ProgressLevels();
	};
}