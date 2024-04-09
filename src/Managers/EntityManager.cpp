#include "EntityManager.h"
#include <algorithm>


Entity EntityManager::NextEntity = 0;

std::vector<Entity> EntityManager::entities;

EntityManager::EntityManager(){}

Entity EntityManager::CreateEntity(){
    entities.push_back(NextEntity);
    return NextEntity++;
}

void EntityManager::DeleteEntity(Entity& entity){
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
}

std::vector<Entity> &EntityManager::GetEntityVector(){
    return entities;
}

int EntityManager::GetEntityCount(){
    return entities.size();
}

