#include <SFML/Graphics.hpp>

#include "src/Core/Game.h"
#include "src/Core/World.h"
#include "src/Entities/Base/BaseEntity.h"
#include "src/Components/Base/Component.h"
#include "src/Components/Visual/SpriteComponent.h"

void Cleanup() {
  delete SWGame::Game::GetGame();
}


int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!",sf::Style::None);
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock clock;
  SWGame::Game* game = SWGame::Game::GetGame();
  auto* ent = game->GetWorld()->CreateEntity(); 
  ent->AddComponent(new SWGame::Component());
  ent->AddComponent(new SWGame::SpriteComponent());
  
  ent->FindComponent<SWGame::SpriteComponent>()->Test();

  game->GetWorld()->CreateEntity();
  game->GetWorld()->CreateEntity();

  float dt;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    
    dt = clock.restart().asSeconds();

    game->Update(dt);

    window.clear();
    window.draw(shape);
    window.display();
  }

  Cleanup();

  return 0;
}