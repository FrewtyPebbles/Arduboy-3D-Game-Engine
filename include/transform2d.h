#pragma once

#include "vec2.h"

class Node2D;

class Transform2D {
public:
  Transform2D(Node2D * node);
  Transform2D(Node2D * node, Vec2I position, Vec2I scale, int16_t rotation);

  Node2D * node;

  Vec2I position = Vec2I(0, 0);
  Vec2F16B scale = Vec2F16B(1.0, 1.0);


  Transform2D get_global_transform();

  void rotate(int16_t angle_deg);
  void set_rotation(int16_t angle_rad);
  uint16_t get_rotation();
private:
  uint16_t rotation = 0;
};