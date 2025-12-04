#pragma once

using SpriteSheet = const uint8_t *;

namespace BitMaps {
  namespace shades {
    namespace size4x4 {

      const uint8_t p100[] PROGMEM = {
        4, 4, // width, height
        0b1111,
        0b1111,
        0b1111,
        0b1111
      };

      const uint8_t p75[] PROGMEM = {
        4, 4, //width, height
        0b1001,
        0b0110,
        0b1001,
        0b0110
      };

      const uint8_t p50[] PROGMEM = {
        4, 4, //width, height
        0b1010,
        0b0101,
        0b1010,
        0b0101
      };

      const uint8_t p25[] PROGMEM = {
        4, 4, // width, height
        0b0101,
        0b0000,
        0b0000,
        0b1010
      };

      const uint8_t p0[] PROGMEM = {
        4, 4, // width, height
        0b0000,
        0b0000,
        0b0000,
        0b0000
      };
    };
  };
};