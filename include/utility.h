#pragma once


extern int __heap_start, *__brkval;



namespace Utility {
  namespace Types {
    template <typename T1, typename T2, bool T1Smaller = (sizeof(T1) < sizeof(T2))>
    struct choose_smaller_type_impl {
        using type = T1;
    };

    // Specialization when T2 is smaller or equal
    template <typename T1, typename T2>
    struct choose_smaller_type_impl<T1, T2, false> {
        using type = T2;
    };

    // Alias
    template <typename T1, typename T2>
    using choose_smaller_type = typename choose_smaller_type_impl<T1, T2>::type;
  };
  

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