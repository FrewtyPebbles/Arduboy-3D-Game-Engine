#include "utility.h"

namespace Utility {
  int freeRam() {
    int v;
    return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
  }
};