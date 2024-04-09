#include "GameWindow.h"

GameWindow::GameWindow() {
  window.create(sf::VideoMode(800, 600), "SFML works!");
  window.setFramerateLimit(60);
  view.setSize(800, 600);

  view.setCenter(TC[0].position.x, TC[0].position.y);
}

void GameWindow::AdjustAspectRatio(sf::Event &event) {
  if (event.type == sf::Event::Resized) {
    windowSize = window.getSize();
    view.setSize(sf::Vector2f(windowSize));
    window.setView(view);
  }
}

void GameWindow::UpdateView() {

  auto &PlayerTransform = TC[0];
  float playerX = PlayerTransform.position.x + 96;
  float playerY = PlayerTransform.position.y + 96;

  view.setCenter(playerX, playerY);
  window.setView(view);
}

void GameWindow::CloseWindow(sf::Event &event) {
  if (event.type == sf::Event::Closed) {
    window.close();
    std::cout << "Window Closed" << std::endl;
  }
}