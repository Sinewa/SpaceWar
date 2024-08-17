#pragma once 

#include "src/Core/Utils/Array.h"

#include "src/Systems/Base/BaseSystem.h"

namespace SWGame{
	class Asteroid;

	class AsteroidSystem : public BaseSystem {
	protected:
		int m_iMaxNumberOfAsteroids = 20;
		float m_fDelay = 2.f;
		float m_fDelayTimer = 2.f;
		float m_fSpeedIncrement = 0.f;
		Array<Asteroid*> m_aAsteroids;
	public:
		AsteroidSystem(int maxNumOfAsteroids);
		virtual void Update(float dt) override;
		void Register(Asteroid* asteroid);
		void UnRegister(Asteroid* asteroid);
	};
}