#pragma once 

#include "src/Entities/Base/BaseEntity.h"
#include "src/Entities/Projectile/Projectile.h"
#include "src/Components/Movement/PlayerMovementControllerComponent.h"
#include "src/Components/Movement/ProjectileControlComponent.h"
#include "src/Components/Visual/SpriteComponent.h"
#include "src/Components/Physics/PhysicsComponent.h"
#include "src/Components/Projectile/ShootingComponent.h"

#include "src/Core/Utils/Transformations.h"

namespace SWPrefabs {
	static SWGame::BaseEntity* CreateShip(const SWGame::VecF& pos, float angle) {
		SWGame::BaseEntity* ship = new SWGame::BaseEntity();
    ship->AddComponent(new SWGame::PlayerMovementControllerComponent());
		auto sprite = new SWGame::SpriteComponent("assets/Ship.png");
    ship->AddComponent(sprite);
		ship->AddComponent(new SWGame::PhysicsComponent(sprite->GetSize()/2, sprite->GetOrigin()));
		ship->AddComponent(new SWGame::ShootingComponent());
		ship->SetTransform({ pos, angle });
		ship->Init();
		return ship;
	}

	static SWGame::BaseEntity* CreateAsteroid(const SWGame::VecF& pos, float angle, SWGame::VecF movementVec, float speed) {
		movementVec.Normalize();
		SWGame::BaseEntity* asteroid = new SWGame::BaseEntity();
		asteroid->AddComponent(new SWGame::ProjectileControlComponent(movementVec, speed));
		auto sprite = new SWGame::SpriteComponent("assets/Asteroid.png");
		asteroid->AddComponent(sprite);
		asteroid->AddComponent(new SWGame::PhysicsComponent(sprite->GetSize()/2, sprite->GetOrigin()));
		asteroid->SetTransform({ pos, angle });
		asteroid->Init();
		return asteroid;
	}

	static SWGame::BaseEntity* CreateProjectile(const SWGame::VecF& pos, float angle, SWGame::VecF movementVec, float speed, float timer) {
		movementVec.Normalize();
		SWGame::BaseEntity* projectile = new SWGame::Projectile(timer);
		auto projComp = new SWGame::ProjectileControlComponent(movementVec, speed);
		projComp->SetRotationSpeed(1440);
		projectile->AddComponent(projComp);
		auto sprite = new SWGame::SpriteComponent("assets/Projectile.png");
		projectile->AddComponent(sprite);
		projectile->AddComponent(new SWGame::PhysicsComponent(sprite->GetSize()/2, sprite->GetOrigin()));
		projectile->SetTransform({ pos, angle });
		projectile->Init();
		return projectile;
	}
}