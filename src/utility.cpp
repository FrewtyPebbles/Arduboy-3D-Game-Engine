#include "utility.h"

namespace Utility {
  int freeRam() {
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
  }

  uint16_t wrap_euler_angle(uint16_t angle) {
      // Wrap to 0..359 efficiently
      angle %= 360;          // now in -359..359
      return angle < 0 ? angle + 360 : angle;
  }
};