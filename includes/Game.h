#include "GameWindow.h"
#include "GlobalCordinateSystem.h"
#include "MapManager.h"
#include "Player.h"
#include "PlayerMovementSystem.h"
#include "RenderSystem.h"

// Debug Includes
#include "ComponentManager.h"

#include <iostream>

class Game {
public:
  Game();

  void run();
  void update(); // Add all updates to this function
  void EventCheck(float &deltaTime);

  void DEBUGSTATEMENT();

  sf::Clock clock;

private:
  
  Player player{window};
  GameWindow window;

  PlayerMovementSystem playerMovementSystem;
  MapManager mapManager;
  RenderSystem renderSystem;
  // Debug includes

  ComponentManager compman;
  GlobalCordinateSystem gcs;
};