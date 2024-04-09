#include <SFML/Graphics.hpp>

#include "ComponentManager.h"
#include "EntityManager.h"
#include "GameWindow.h"

class Player {

public:
  Player(GameWindow &window);

  void PlayerTexAndSprite();
  void AddPlayerComponents();

private:
  ComponentManager componentManager;
  GameWindow &gameWindow;

  sf::RenderWindow &window = gameWindow.getWindow();
  sf::Sprite playerSprite;
  std::string playerTexturePath;
  sf::Texture playerTexture;
};