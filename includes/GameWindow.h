#include "ComponentManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

class GameWindow {

public:
  GameWindow();

  sf::RenderWindow window;

  void AdjustAspectRatio(sf::Event &event);
  void CloseWindow(sf::Event &event);
  void UpdateView();

  sf::RenderWindow &getWindow() { return window; }

  sf::View view;
  sf::Vector2u windowSize;

  std::unordered_map<Entity, TransformComponent> &TC = ComponentManager::GetComponentMap<TransformComponent>();
  std::unordered_map<Entity, RenderComponent> &RC = ComponentManager::GetComponentMap<RenderComponent>();

private:
  ComponentManager compman;
};

#endif