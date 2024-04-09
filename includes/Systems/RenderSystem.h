#include "ComponentManager.h"
#include "MapManager.h"
class RenderSystem {
public:
  RenderSystem() = default;

  void draw(sf::RenderWindow &window);

  bool isInCameraView(sf::RenderWindow &window, Entity &entity);

private:
  std::unordered_map<Entity, RenderComponent> &renderComponents =
      ComponentManager::GetComponentMap<RenderComponent>();

  std::unordered_map<Entity, TransformComponent> &transformComponents =
      ComponentManager::GetComponentMap<TransformComponent>();

  std::vector<sf::Sprite> Tiles;
  int RenderCount = 0;

  ComponentManager componentManager;
  // MapManager mapManager;
};