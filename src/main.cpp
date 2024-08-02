#include <SFML/Graphics.hpp>

#include "src/Game/Game.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!",sf::Style::None);
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock clock;
  SWGame::Game game;
  game.CreateEntity();
  float dt;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    
    dt = clock.restart().asSeconds();

    game.UpdateEntities(dt);

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}