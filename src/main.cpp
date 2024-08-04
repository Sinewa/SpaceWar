#include <SFML/Graphics.hpp>

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Entities/Base/BaseEntity.h"
#include "src/Components/Base/Component.h"
#include "src/Components/Visual/SpriteComponent.h"

void Cleanup() {
  //delete SWGame::Game::GetGame();
}


int main() {
  SWGame::Game* game = SWGame::Game::GetGame();
  auto* ent = game->GetWorld()->CreateEntity(); 
  ent->AddComponent(new SWGame::Component());
  ent->AddComponent(new SWGame::SpriteComponent());
  ent->Init();
  
  game->GetWorld()->CreateEntity();
  game->GetWorld()->CreateEntity();
    
  game->Run();
  
  Cleanup();

  return 0;
}