#include "AsteroidSystem.h"

#include "src/Prefabs/BasePrefab.h"
#include "src/Core/Utils/Utils.h"
#include "src/Core/Game.h"
#include "src/Core/World.h"

namespace SWGame {
	//-----------------------------------------------------------
	AsteroidSystem::AsteroidSystem(int maxNumOfAsteroids) 
	: m_iMaxNumberOfAsteroids(maxNumOfAsteroids)
	{

	}
	//-----------------------------------------------------------
	void AsteroidSystem::Update(float dt) {

		m_fDelayTimer += dt;
		if (m_aAsteroids.size() >= m_iMaxNumberOfAsteroids)
			return;
		if (m_fDelayTimer < m_fDelay)
			return;
		if (m_fSpeedIncrement >= 20.f) {
			m_fSpeedIncrement = 10.f;
			m_iMaxNumberOfAsteroids++;
		}
		VecF pos(Random::GetRandomInt()%200-100, Random::GetRandomInt()%200-100);

		auto asteroid = SWPrefabs::CreateAsteroid(pos, Random::GetRandomFloat01(), pos, 10.f + Random::GetRandomFloat01()*30.f+ m_fSpeedIncrement);
		Register(asteroid);
		Game::GetGame()->GetActiveWorld()->AddEntity(asteroid);
	}
	//-----------------------------------------------------------
	void AsteroidSystem::Register(Asteroid* asteroid) {
		m_aAsteroids.push_back(asteroid);
	}
	//-----------------------------------------------------------
	void AsteroidSystem::UnRegister(Asteroid* asteroid) {
		for (int i = 0; i < m_aAsteroids.size(); i++) {
			if (m_aAsteroids[i] == asteroid) {
				m_fSpeedIncrement += 1.f;
				m_aAsteroids.FastErase(i);
			}
		}
	}
	//-----------------------------------------------------------
}