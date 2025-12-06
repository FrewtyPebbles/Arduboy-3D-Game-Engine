#pragma once

#include "vec2.h"

class Node2D;

class Transform2D {
public:
  Transform2D(Node2D * node);
  Transform2D(Node2D * node, Vec2I position, Vec2I scale, fraction<uint8_t, uint8_t> rotation);

  Node2D * node;

  Vec2I position = Vec2I(0, 0);
  Vec2F16B scale = Vec2F16B(1.0, 1.0);


  Transform2D get_global_transform();

  template<typename N, typename D>
  void rotate(fraction<N, D> angle_rad);

  template<typename N, typename D>
  void set_rotation(fraction<N, D> angle_rad);

  fraction<uint8_t, uint8_t> get_rotation();

private:
  fraction<uint8_t, uint8_t> rotation = 0;
};