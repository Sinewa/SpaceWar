#pragma once 

#include "src/Entities/Base/BaseEntity.h"
#include "src/Entities/Game/Asteroid.h"
#include "src/Entities/Projectile/Projectile.h"
#include "src/Components/Movement/PlayerMovementControllerComponent.h"
#include "src/Components/Movement/ProjectileControlComponent.h"
#include "src/Components/Visual/SpriteComponent.h"
#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Components/Physics/ShipPhysicsComponent.h"
#include "src/Components/Physics/ProjectilePhysicsComponent.h"
#include "src/Components/Physics/AsteroidPhysicsComponent.h"
#include "src/Components/Projectile/ShootingComponent.h"

#include "src/Core/World.h"
#include "src/Core/Utils/Transformations.h"

namespace SWPrefabs {
	static SWGame::BaseEntity* CreateShip(SWGame::World* world, const SWGame::VecF& pos, float angle) {
		SWGame::Ship* ship = new SWGame::Ship();
    ship->AddComponent(new SWGame::PlayerMovementControllerComponent());
		auto sprite = new SWGame::SpriteComponent("assets/Ship.png");
    ship->AddComponent(sprite);
		ship->AddComponent(new SWGame::ShipPhysicsComponent(sprite->GetSize()/2, sprite->GetOrigin()));
		ship->AddComponent(new SWGame::ShootingComponent());
		ship->SetTransform({ pos, angle });
		ship->Init(world);
		return ship;
	}

	static SWGame::Asteroid* CreateAsteroid(SWGame::World* world, const SWGame::VecF& pos, float angle, SWGame::VecF movementVec, float speed) {
		movementVec.Normalize();
		SWGame::Asteroid* asteroid = new SWGame::Asteroid();
		asteroid->AddComponent(new SWGame::ProjectileControlComponent(movementVec, speed));
		auto sprite = new SWGame::SpriteComponent("assets/Asteroid.png");
		asteroid->AddComponent(sprite);
		asteroid->AddComponent(new SWGame::AsteroidPhysicsComponent(sprite->GetSize()/2, sprite->GetOrigin()));
		asteroid->SetTransform({ pos, angle });
		asteroid->Init(world);
		return asteroid;
	}

	static SWGame::Projectile* CreateProjectile(SWGame::World* world, const SWGame::VecF& pos, float angle, SWGame::VecF movementVec, float speed, float timer) {
		movementVec.Normalize();
		SWGame::Projectile* projectile = new SWGame::Projectile(timer);
		auto projComp = new SWGame::ProjectileControlComponent(movementVec, speed);
		projComp->SetRotationSpeed(1440);
		projectile->AddComponent(projComp);
		auto sprite = new SWGame::SpriteComponent("assets/Projectile.png");
		projectile->AddComponent(sprite);
		projectile->AddComponent(new SWGame::ProjectilePhysicsComponent(sprite->GetSize()/2, sprite->GetOrigin()));
		projectile->SetTransform({ pos, angle });
		projectile->Init(world);
		return projectile;
	}

	static SWGame::BaseEntity* CreateSelector(SWGame::World* world, const SWGame::VecF& pos, float angle) {
		SWGame::BaseEntity* ship = new SWGame::BaseEntity();
		auto sprite = new SWGame::SpriteComponent("assets/Ship.png");
		ship->AddComponent(sprite);
		auto physics = new SWGame::PhysicsComponent(sprite->GetSize() / 2, sprite->GetOrigin());
		physics->SetImmune(true);
		ship->AddComponent(physics);
		ship->SetTransform({ {pos.x + sprite->GetSize() / 2, pos.y + sprite->GetSize() / 2}, angle });
		ship->Init(world);
		return ship;
	}
}