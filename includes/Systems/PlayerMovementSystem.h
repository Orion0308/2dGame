#include "ComponentManager.h"
#include "EntityManager.h"

class PlayerMovementSystem {

public:
  PlayerMovementSystem() = default;
  void MovePlayer(float &deltaTime);

private:
  std::unordered_map<Entity, TransformComponent> &transformComponents =
      ComponentManager::GetComponentMap<TransformComponent>();

  float PlayerSpeed = transformComponents[0].speed;
};