#pragma once 

#include "src/Entities/Base/BaseEntity.h"
#include "src/Components/Movement/PlayerMovementControllerComponent.h"
#include "src/Components/Movement/AsteroidControlComponent.h"
#include "src/Components/Visual/SpriteComponent.h"
#include "src/Components/Physics/PhysicsComponent.h"

#include "src/Core/Utils/Transformations.h"

namespace SWPrefabs {
	static SWGame::BaseEntity* CreateShip(const SWGame::VecF& pos, float angle) {
		SWGame::BaseEntity* ship = new SWGame::BaseEntity();
    ship->AddComponent(new SWGame::PlayerMovementControllerComponent());
    ship->AddComponent(new SWGame::SpriteComponent("assets/Ship.png"));
		ship->AddComponent(new SWGame::PhysicsComponent());
		ship->SetTransform({ pos, angle });
		ship->Init();
		return ship;
	}

	static SWGame::BaseEntity* CreateAsteroid(const SWGame::VecF& pos, float angle, SWGame::VecF movementVec, float speed) {
		movementVec.Normalize();
		SWGame::BaseEntity* asteroid = new SWGame::BaseEntity();
		asteroid->AddComponent(new SWGame::AsteroidControlComponent(movementVec, speed));
		asteroid->AddComponent(new SWGame::SpriteComponent("assets/Asteroid.png"));
		asteroid->AddComponent(new SWGame::PhysicsComponent());
		asteroid->SetTransform({ pos, angle });
		asteroid->Init();
		return asteroid;
	}
}