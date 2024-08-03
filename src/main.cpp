#include <SFML/Graphics.hpp>

#include "src/Game/Game.h"
#include "src/Core/World.h"
#include "src/Core/Entity.h"
#include "src/Core/Component.h"
#include "src/Visual/SpriteComponent.h"

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