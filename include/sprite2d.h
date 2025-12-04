#pragma once

#include "node2d.h"
#include "vector.h"
#include "bitmaps.h"

class Sprite2D : public Node2D {
public:
  Sprite2D(uint8_t id, Node ** children = nullptr, uint16_t children_count = 0, SpriteSheet sprite_sheet = nullptr, uint8_t frame_count = 0, uint8_t initial_frame = 0);

  void update(Scene * scene, Arduboy2 & arduboy, const Sprites & sprites) override;

  uint8_t get_width();
  uint8_t get_height();
  
  uint8_t frame = 0;
  uint8_t frame_count = 0;
  SpriteSheet sprite_sheet = nullptr;
};