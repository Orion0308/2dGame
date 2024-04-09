#include <SFML/Graphics.hpp>

#ifndef GLOBALCORDINATESYSTEM_H
#define GLOBALCORDINATESYSTEM_H

class GlobalCordinateSystem {

public:
  std::pair<float, float> WindowToWorldCords(float x, float y) {

    float x2 = x + 100;
    float y2 = y + 100;
    return std::make_pair(x2, y2);
  }

  std::pair<float, float> WorldToWindowCords(float x, float y) {
    float x2 = x - 100;
    float y2 = y - 100;
    return std::make_pair(x2, y2);
  }
};

#endif