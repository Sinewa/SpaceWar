#include "Asteroid.h"

#include <SFML/Graphics/Sprite.hpp>

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Core/Managers/SystemsManager.h"
#include "src/Systems/Game/AsteroidSystem.h"
#include "src/Systems/Game/GameModeSystem.h"

#include "src/Components/Visual/SpriteComponent.h"
#include "src/Components/Physics/AsteroidPhysicsComponent.h"

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
		auto sprite = FindComponent<SpriteComponent>();
		auto physics = FindComponent<AsteroidPhysicsComponent>();

		sprite->GetSprite()->setScale(size, size);
		physics->SetScale(size);
		m_size = size;
	}
	//-----------------------------------------------------------
	void Asteroid::OnHit() {

	}
}