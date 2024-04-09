#include "Game.h"
#include <iostream>
Game::Game() {}

void Game::run() {

  while (window.window.isOpen()) {

    float deltaTime = clock.restart().asSeconds();

    window.window.clear();

    EventCheck(deltaTime);

    window.window.setView(window.view);

    playerMovementSystem.MovePlayer(deltaTime);

    window.UpdateView();

    renderSystem.draw(window.window);
    DEBUGSTATEMENT();

    window.window.display();
    std::cout << "Entity Count: " << EntityManager::entities.size()
              << std::endl;
    std::cout << "Delta Time: " << deltaTime << std::endl;
  }
}

void Game::DEBUGSTATEMENT() {

  float x =
      ComponentManager::GetComponentMap<TransformComponent>()[0].position.x;
  float y =
      ComponentManager::GetComponentMap<TransformComponent>()[0].position.y;
  auto pos = gcs.WindowToWorldCords(x, y);
  std::cout << "Player Position: " << pos.first << ", " << pos.second
            << std::endl;
}

void Game::EventCheck(float &deltaTime) {
  sf::Event event;
  while (window.window.pollEvent(event)) {
    window.CloseWindow(event);
    window.AdjustAspectRatio(event);
  }
}
