#pragma once
#include "vec3.h"
#include "vec4.h"
#include "vec2.h"


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

    // Default: not a float type
    template <typename T>
    struct is_float_type {
        static const bool value = false;
    };

    // Specializations for your “float” types
    template <> struct is_float_type<float>  { static const bool value = true; };
    template <> struct is_float_type<double> { static const bool value = true; };
    template <> struct is_float_type<Vec2F> { static const bool value = true; };
    template <> struct is_float_type<Vec3F> { static const bool value = true; };

    // default is a float
    template <typename T1, typename T2, bool T1Float = is_float_type<T1>::value>
    struct choose_float_type_impl {
        using type = T1;
    };

    // Specialization: if T1 is a float type
    template <typename T1, typename T2>
    struct choose_float_type_impl<T1, T2, false> {
        using type = T2;
    };

    // Alias
    template <typename T1, typename T2>
    using choose_float_type = typename choose_float_type_impl<T1, T2>::type;
  };
  

  template <typename T1, typename T2, typename RatioType>
  auto lerp(T1 a, T2 b, RatioType t) -> Types::choose_smaller_type<T1,T2> {
      using S = Types::choose_smaller_type<T1, T2>;
      S a_small = static_cast<S>(a);
      S b_small = static_cast<S>(b);
      return static_cast<Types::choose_float_type<T1, S>>(a_small + t * (b_small - a_small));
  }

  uint16_t wrap_euler_angle(uint16_t angle);

  template<typename T>
  Vec2<T> wrap_euler_angle(Vec2<T> euler_angles) {
    return Vec2<T>(euler_angles.x, euler_angles.y);
  }

  template<typename T>
  Vec3<T> wrap_euler_angle(Vec3<T> euler_angles) {
    return Vec3<T>(euler_angles.x, euler_angles.y, euler_angles.z);
  }

  template<typename T>
  Vec4<T> wrap_euler_angle(Vec4<T> euler_angles) {
    return Vec4<T>(euler_angles.x, euler_angles.y, euler_angles.z, euler_angles.w);
  }

  int freeRam();
};