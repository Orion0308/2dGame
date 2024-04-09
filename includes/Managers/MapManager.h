#include "ComponentManager.h"
#include "EntityManager.h"
#include "GlobalCordinateSystem.h"

#ifndef MAPMANAGER_H
#define MAPMANAGER_H

class MapManager {
public:
  MapManager();
  void InitMap();

  std::vector<sf::Sprite> TilesLayerVector;

private:
  std::vector<std::vector<Entity>> map;
  int MapWidth;
  int MapHeight;
  GlobalCordinateSystem gcs;

  // Tiles
  std::string GrassTilePath = "../assets/Terrain/tile011.png";
  sf::Sprite GrassTileSprite;
  sf::Texture GrassTileTexture;

  void InitGrassTile(std::string &path) {
    GrassTileTexture.loadFromFile(path);
    GrassTileSprite.setTexture(GrassTileTexture);
  }
};

#endif