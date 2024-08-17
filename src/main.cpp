#include <SFML/Graphics.hpp>

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Entities/Base/BaseEntity.h"

#include "src/Components/Movement/PlayerMovementControllerComponent.h"
#include "src/Components/Visual/SpriteComponent.h" 

#include "src/Prefabs/BasePrefab.h"

#include "src/Worlds/InitWorld.h"
#include "src/Worlds/MenuWorld.h"
#include "src/Worlds/GameWorld.h"

void Cleanup() {
  //delete SWGame::Game::GetGame();
}


int main() {
  SWGame::Game* game = SWGame::Game::GetGame();
  
  game->RegisterWorld(new SWGame::InitWorld());
  game->RegisterWorld(new SWGame::MenuWorld());
  game->RegisterWorld(new SWGame::GameWorld());
  
  SWGame::World* world = game->GetActiveWorld();
  world->Init();

  world->AddEntity(SWPrefabs::CreateShip({ 400, 400 }, 0.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 100 }, 1.f, { 1.f, 0.f }, 10.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 120 }, 1.f, { 1.f, 0.f }, 20.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 140 }, 1.f, { 1.f, 0.f }, 30.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 160 }, 1.f, { 1.f, 0.f }, 40.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 180 }, 1.f, { 1.f, 0.f }, 50.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 200 }, 1.f, { 1.f, 0.f }, 60.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 220 }, 1.f, { 1.f, 0.f }, 70.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 240 }, 1.f, { 1.f, 0.f }, 80.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 260 }, 1.f, { 1.f, 0.f }, 90.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 280 }, 1.f, { 1.f, 1.f }, 100.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 300 }, 1.f, { 1.1f, 2.f }, 10.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 320 }, 1.f, { 3.4f, 3.f }, 10.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 340 }, 1.f, { 4.7f, 4.f }, 10.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 360 }, 1.f, { 9.f, 5.f }, 10.f));
  world->AddEntity(SWPrefabs::CreateAsteroid({ 100, 380 }, 1.f, { 1.f, 6.f }, 10.f));

  game->Run();
  
  Cleanup();

  return 0;
}