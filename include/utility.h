#pragma once
#include "types.h"

extern int __heap_start, *__brkval;



namespace Utility {
  template <typename T1, typename T2, typename RatioType>
  auto lerp(T1 a, T2 b, RatioType t) -> Types::choose_smaller_type<T1,T2> {
      using S = Types::choose_smaller_type<T1, T2>;
      S a_small = static_cast<S>(a);
      S b_small = static_cast<S>(b);
      return a_small + t * (b_small - a_small);
  }

  template<typename T>
  T wrap_euler_angle(T angle) {
    angle %= static_cast<T>(360);
    return angle < static_cast<T>(0) ? angle + static_cast<T>(360) : angle;
  }

  int freeRam();
};