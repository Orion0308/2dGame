#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "EntityManager.h"

#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

// Components

struct HPComponent {
  int hp;
};

struct TransformComponent {
  sf::Vector2f position;
  float speed;
};

struct RenderComponent {
  sf::Sprite sprite;
  sf::Texture texture;
  std::string texturePath;
  int layer;
};

struct TileComponent {
  int TileID;
};

class ComponentManager {

public:
  ComponentManager() = default;

  // Variables

  // Functions

  template <typename T> static void AddComponent(Entity &entity, T component) {
    // Add the component to the appropriate map
    GetComponentMap<T>()[entity] = component;
  }

  template <typename T> static T &GetComponent(Entity &entity) {
    // Get the component from the appropriate map
    return GetComponentMap<T>()[entity];
  }

  template <typename T> static void RemoveComponent(Entity &entity) {
    // Remove the component from the appropriate map
    GetComponentMap<T>().erase(entity);
  }

  template <typename T>
  static std::unordered_map<Entity, T> &GetComponentMap() {
    // Return the appropriate map
    static std::unordered_map<Entity, T> componentMap;
    return componentMap;
  }

private:
  std::unordered_map<Entity, HPComponent> HPComponentMap;
  std::unordered_map<Entity, TransformComponent> TransformComponentMap;
  std::unordered_map<Entity, RenderComponent> RenderComponentMap;
};

#endif