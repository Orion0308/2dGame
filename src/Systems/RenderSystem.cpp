#include "RenderSystem.h"
#include "GlobalCordinateSystem.h"
#include <iostream>

void RenderSystem::draw(sf::RenderWindow &window) {

  for (auto &pair : renderComponents) {

    Entity entity = pair.first;
    TransformComponent &transformComponent = transformComponents[entity];
    std::cout<<"Drawing entity: "<<entity<<" At position: "<<transformComponent.position.x<<", "<<transformComponent.position.y<<"\n";

    if (!isInCameraView(window, entity)) {
      continue;
    }

    RenderComponent &renderComponent = pair.second;

    renderComponent.sprite.setPosition(transformComponent.position);

    window.draw(renderComponent.sprite);
  }
}

bool RenderSystem::isInCameraView(sf::RenderWindow &window, Entity &entity) {

  auto view = window.getView();
  auto sizeX = view.getSize().x;
  auto sizeY = view.getSize().y;

  auto positionOfEntity = transformComponents[entity].position;
  if (positionOfEntity.x > view.getCenter().x + sizeX / 2 + 64 ||
      positionOfEntity.x < view.getCenter().x - sizeX / 2 - 64) {
    return false;
  }
  return true;
}