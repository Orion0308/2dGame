#include <cstdint>
#include <vector>

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

using Entity = uint32_t;

class EntityManager {

public:
  EntityManager();
  // Variables
  static Entity NextEntity;

  static std::vector<Entity> entities;

  // Functions
  static Entity CreateEntity();

  void DeleteEntity(Entity &entity);

  std::vector<Entity> &GetEntityVector();

  int GetEntityCount();
};

#endif