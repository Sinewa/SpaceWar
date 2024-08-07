#include <SFML/Graphics.hpp>

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Entities/Base/BaseEntity.h"

#include "src/Components/Movement/PlayerMovementControllerComponent.h"
#include "src/Components/Visual/SpriteComponent.h"

void Cleanup() {
  //delete SWGame::Game::GetGame();
}


int main() {
  SWGame::Game* game = SWGame::Game::GetGame();
  auto* ent = game->GetWorld()->CreateEntity(); 
  ent->AddComponent(new SWGame::PlayerMovementControllerComponent());
  ent->AddComponent(new SWGame::SpriteComponent());
  ent->Init();
  
  ent = game->GetWorld()->CreateEntity();
  ent->AddComponent(new SWGame::PlayerMovementControllerComponent());
  ent->AddComponent(new SWGame::SpriteComponent());
  ent->Init();
  //ent->SetTranslation();
  ent->SetTransform({ { 100, 100 } , 1.f });
    
  game->Run();
  
  Cleanup();

  return 0;
}