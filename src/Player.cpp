#include "Player.h"

Player::Player(GameWindow &window) : gameWindow(window) {

  playerTexturePath = "../assets/Knight/tile000.png";

  PlayerTexAndSprite();
  AddPlayerComponents();
}

void Player::PlayerTexAndSprite() {
  playerTexture.loadFromFile(playerTexturePath);
  playerSprite.setTexture(playerTexture);
}

void Player::AddPlayerComponents() {

  Entity playerEntity = EntityManager::CreateEntity();
  ComponentManager::AddComponent(playerEntity, HPComponent{100});
  ComponentManager::AddComponent(playerEntity,
                                 TransformComponent{{0.0f, 0.0f}, 30.0f});
  ComponentManager::AddComponent(
      playerEntity,
      RenderComponent{playerSprite, playerTexture, playerTexturePath, 1});
}