#include "AsteroidSystem.h"

#include "src/Prefabs/BasePrefab.h"
#include "src/Core/Utils/Utils.h"
#include "src/Core/Utils/Transformations.h"
#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"

#include "src/Systems/Game/GameModeSystem.h"
#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	AsteroidSystem::AsteroidSystem(int maxNumOfAsteroids)
	: BaseSystem()
	,	m_iMaxNumberOfAsteroids(maxNumOfAsteroids)
	{

	}
	//-----------------------------------------------------------
	void AsteroidSystem::Init(World* world) {
		BaseSystem::Init(world);

		m_gmSys = GetWorld()->GetSystems()->FindSystem<GameModeSystem>();
	}
	//-----------------------------------------------------------
	void AsteroidSystem::ReInit() {

		for (int i = 0; i < m_aAsteroids.size(); i++) {
			m_aAsteroids[i]->SetFlags(EntityFlags::EF_DELETE);
		}
	}
	//-----------------------------------------------------------
	void AsteroidSystem::Update(float dt) {

		m_fDelayTimer += dt;
		Level level;
		if (m_gmSys)
			level = m_gmSys->GetCurrentLevel();

		if (m_aAsteroids.size() >= (m_gmSys ? level.m_asteroidMaxNum : m_iMaxNumberOfAsteroids))
			return;
		if (m_fDelayTimer < m_fDelay)
			return;
		VecF pos(Random::GetRandomInt()%200-100, Random::GetRandomInt()%200-100);
		VecF movementVec(Random::GetRandomInt() % 200 - 100, Random::GetRandomInt() % 200 - 100);
		if (pos.x < 0)
			pos.x += 800;
		if (pos.y < 0)
			pos.y += 800;
		if (m_ship) {
			if ((pos - m_ship->GetTranslation()).Length() < m_exclusionZone)
				return;
		}

		auto asteroid = SWPrefabs::CreateAsteroid(GetWorld(), pos, Random::GetRandomFloat01(), movementVec, level.m_asteroidSpeed + Random::GetRandomFloat01() * 30.f + level.m_asteroidSpeed);
		asteroid->SetSize(level.m_asteroidMaxSize);
		Register(asteroid);
		GetWorld()->AddEntity(asteroid);
	}
	//-----------------------------------------------------------
	void AsteroidSystem::Register(Asteroid* asteroid) {
		m_aAsteroids.push_back(asteroid);
	}
	//-----------------------------------------------------------
	void AsteroidSystem::UnRegister(Asteroid* asteroid) {
		for (int i = 0; i < m_aAsteroids.size(); i++) {
			if (m_aAsteroids[i] == asteroid) {
				m_aAsteroids.FastErase(i);
			}
		}
	}
	//-----------------------------------------------------------
	void AsteroidSystem::RegisterShip(BaseEntity* ship) {
		m_ship = ship;
	}
	//-----------------------------------------------------------
}