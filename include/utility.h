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

  // Generic sqrt for floating point and integer types
  template<typename T>
  constexpr T sqrt(T x)
  {
      if (x <= T(0))
          return T(0);

      // Good initial guess
      T guess = x > T(1) ? x / T(2) : T(1);

      // Newton iterations – fast & accurate
      // More iterations for better accuracy
      for (int i = 0; i < 5; i++)
          guess = (guess + x / guess) / T(2);

      return guess;
  }

  // Generic pow function
  template<typename T>
  T pow(const T& base, int8_t exponent)
  {
      if (exponent == 0)
          return T(1);

      T result = T(1);
      T b = base;
      int8_t exp = exponent;

      if (exp < 0)
      {
          b = T(1) / b;
          exp = -exp;
      }

      // Fast exponentiation using binary method
      while (exp > 0)
      {
          if (exp % 2 != 0)       // multiply when the current bit is 1
              result = result * b;
          b = b * b;              // square the base
          exp /= 2;
      }

      return result;
  }

  int freeRam();
};