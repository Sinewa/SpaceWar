#include "Asteroid.h"

#include <SFML/Graphics/Sprite.hpp>

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Game/AsteroidSystem.h"
#include "src/Systems/Game/GameModeSystem.h"

#include "src/Components/Visual/SpriteComponent.h"
#include "src/Components/Physics/AsteroidPhysicsComponent.h"
#include "src/Components/Game/DamageComponent.h"

namespace SWGame {
	//-----------------------------------------------------------
	void Asteroid::OnDelete(){
		BaseEntity::OnDelete();

		auto asteroidSys = GetWorld()->GetSystems()->FindSystem<AsteroidSystem>();
		if (asteroidSys) {
			asteroidSys->UnRegister(this);
		}
		
		auto gmSys = GetWorld()->GetSystems()->FindSystem<GameModeSystem>();
		if (gmSys) {
			gmSys->OnAsteroidDestroyed(this);
		}
		
	}
	//-----------------------------------------------------------
	void Asteroid::SetSize(float size) {
		if (auto sprite = FindComponent<SpriteComponent>())
			sprite->GetSprite()->setScale(size, size);

		if (auto physics = FindComponent<AsteroidPhysicsComponent>())
			physics->SetScale(size);

		if (auto damage = FindComponent<DamageComponent>())
			damage->SetHP(size);
		m_size = size;
	}
}