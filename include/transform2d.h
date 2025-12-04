#pragma once

#include "vector.h"

class Node2D;

class Transform2D {
public:
  Transform2D(Node2D * node);
  Transform2D(Node2D * node, Vec2I position, Vec2I scale, int16_t rotation);

  Node2D * node;

  Vec2I position = Vec2I(0, 0);
  Vec2F scale = Vec2I(1.0, 1.0);


  Transform2D get_global_transform();

  void rotate(int16_t angle_deg);
  void set_rotation(int16_t angle_rad);
  uint16_t get_rotation();
private:
  uint16_t rotation = 0;
  inline uint16_t wrap_angle(uint16_t angle) {
      // Wrap to 0..359 efficiently
      angle %= 360;          // now in -359..359
      return angle < 0 ? angle + 360 : angle;
  }
};