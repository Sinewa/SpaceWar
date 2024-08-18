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
  game->Init();
  game->Run();
  
  Cleanup();

  return 0;
}