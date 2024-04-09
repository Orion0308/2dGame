#include "PlayerMovementSystem.h"
#include <iostream>

void PlayerMovementSystem::MovePlayer(float &deltaTime) {
  TransformComponent &playerTransform = transformComponents[0];

  float movementSpeed = PlayerSpeed * deltaTime;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    playerTransform.position.y -= movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    playerTransform.position.x -= movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    playerTransform.position.y += movementSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    playerTransform.position.x += movementSpeed;
  }
}
