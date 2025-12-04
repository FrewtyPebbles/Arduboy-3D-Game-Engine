#pragma once
#include <stdint.h>
#include "vector.h"
// This is a frame buffer which can be rendered to the screen.

class FrameBuffer {
public:
  FrameBuffer();
  FrameBuffer(uint8_t * _data, const Vec2I & dimensions);

  void set_data(uint8_t * _data, const Vec2I & dimensions);

  uint8_t * data;
  uint16_t data_size;
  Vec2I dimensions;
};
