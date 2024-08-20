#pragma once 

#include "src/Core/Utils/Array.h"

#include "src/Systems/Base/BaseSystem.h"

namespace SWGame{
	class Asteroid;
	class GameModeSystem;
	class BaseEntity;

	class AsteroidSystem : public BaseSystem {
	protected:
		int m_iMaxNumberOfAsteroids = 20;
		float m_fDelay = 2.f;
		float m_fDelayTimer = 2.f;
		Array<Asteroid*> m_aAsteroids;
		GameModeSystem* m_gmSys;

		BaseEntity* m_ship;
		float m_exclusionZone = 300.f;
	public:
		AsteroidSystem(int maxNumOfAsteroids);
		virtual void Init(World* world);
		virtual void ReInit();
		virtual void Update(float dt) override;
		void Register(Asteroid* asteroid);
		void RegisterShip(BaseEntity* ship);
		void UnRegister(Asteroid* asteroid);
	};
}