#include <stdint.h>
#include "frame_buffer.h"

FrameBuffer::FrameBuffer() : data(nullptr), data_size(0), dimensions(Vec2I(0,0)) {}
FrameBuffer::FrameBuffer(uint8_t * _data, const Vec2I & dimensions) {
  set_data(_data, dimensions);
}

void FrameBuffer::set_data(uint8_t * data, const Vec2I & dimensions) {
  this->data = data;
  this->dimensions = dimensions;
  this->data_size = dimensions.x * dimensions.y;
}
