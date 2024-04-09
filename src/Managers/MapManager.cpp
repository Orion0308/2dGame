#include "MapManager.h"

#include <iostream>

#include "GameWindow.h"
MapManager::MapManager() {
  MapWidth = 2;
  MapHeight = 2;
  map.resize(MapWidth, std::vector<Entity>(MapHeight));
  InitMap();
}

void MapManager::InitMap() {

  for (int i = 0; i < MapWidth; i++) {
    for (int j = 0; j < MapHeight; j++) {
      auto tile = EntityManager::CreateEntity();
      float x = i;
      float y = j;

      auto TilePos = gcs.WindowToWorldCords(x * 64, y * 64);
      std::cout << "Creating tile at (" << i << ", " << j << ") with position ("
                << TilePos.first << ", " << TilePos.second << ")\n";
      auto TilePosx = TilePos.first;
      auto TilePosy = TilePos.second;

      ComponentManager::AddComponent(
          tile, TransformComponent{{TilePosx, TilePosy}, 0.0f});

      ComponentManager::AddComponent(tile, TileComponent{1});

      ComponentManager::AddComponent(
          tile,
          RenderComponent{GrassTileSprite, GrassTileTexture, GrassTilePath});

      InitGrassTile(GrassTilePath);

      map[i][j] = tile;
    }
  }
}