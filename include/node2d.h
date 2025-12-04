#pragma once

#include "node.h"
#include "vec2.h"
#include "transform2d.h"

class Node2D : public Node {
public:
  Node2D(uint8_t id, Node ** children = nullptr, uint16_t children_count = 0);

  Transform2D transform = Transform2D(this);

  void update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) override;
};

