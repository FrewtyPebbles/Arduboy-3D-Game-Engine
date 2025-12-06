#pragma once

#include "fraction_utilities.h"
#include "fraction.h"
#include "utility.h"

#include <stdint.h>
#include <math.h>

// VEC2

template<typename T> struct Vec2 {
  Vec2(T x = static_cast<T>(0), T y = static_cast<T>(0));
  template<typename U>
  Vec2<T>(const Vec2<U> & other);

  T x, y;

  template<typename U>
  Vec2<T> operator*(const U& other) const;

  friend Vec2<T> operator*(const uint8_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const uint16_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const uint32_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const uint64_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const int8_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const int16_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const int32_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  friend Vec2<T> operator*(const int64_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  template<typename N, typename D>
  friend Vec2<T> operator*(const fraction<N, D>& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs * rhs.x, lhs * rhs.y);
  }

  template<typename U>
  Vec2<T> operator*(const Vec2<U>& other) const;

  Vec2<float> operator*(const Vec2<float>& other) const;

  template<typename U>
  Vec2<T> operator/(const U& other) const;

  friend Vec2<T> operator/(const uint8_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const uint16_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const uint32_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const uint64_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const int8_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const int16_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const int32_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  friend Vec2<T> operator/(const int64_t& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  template<typename N, typename D>
  friend Vec2<T> operator/(const fraction<N, D>& lhs, const Vec2<T>& rhs) {
      return Vec2<T>(lhs / rhs.x, lhs / rhs.y);
  }

  template<typename U>
  Vec2<T> operator/(const Vec2<U>& other) const;

  Vec2<float> operator/(const Vec2<float>& other) const;
  
  template<typename U>
  Vec2<T> operator+(const Vec2<U>& other) const;
  
  Vec2<float> operator+(const Vec2<float>& other) const;

  template<typename U>
  Vec2<T> operator-(const Vec2<U>& other) const;

  Vec2<float> operator-(const Vec2<float>& other) const;

  void operator*=(const Vec2& other);

  template<typename U>
  void operator*=(const Vec2<U>& other);

  void operator/=(const Vec2& other);
  
  template<typename U>
  void operator/=(const Vec2<U>& other);
  
  void operator+=(const Vec2& other);

  template<typename U>
  void operator+=(const Vec2<U>& other);

  void operator-=(const Vec2& other);

  template<typename U>
  void operator-=(const Vec2<U>& other);

  T dot(const Vec2& other) const;

  T det(const Vec2& other) const;

  template<typename N, typename D>
  fraction<N,D> angle_between(const Vec2& other) const;

  template<typename N, typename D>
  fraction<N, D> magnitude() const;

  template<typename N, typename D>
  Vec2 rotate(fraction<N, D> angle_degrees) const;

  template<typename N, typename D>
  Vec2<fraction<N, D>> project_onto(const Vec2<fraction<N, D>> & other) const;

};

template<typename T>
Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}

template<typename T>
template<typename U>
Vec2<T>::Vec2(const Vec2<U> & other) : x(other.x), y(other.y) {}

template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator*(const U& other) const {
  return Vec2<T>(this->x * other, this->y * other);
}



template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator*(const Vec2<U>& other) const {
  return Vec2<T>(static_cast<T>(this->x * other.x), static_cast<T>(this->y * other.y));
}

template<typename T>
Vec2<float> Vec2<T>::operator*(const Vec2<float>& other) const {
  return Vec2<float>(this->x * other.x, this->y * other.y);
}

template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator/(const U& other) const {
  return Vec2<T>(this->x / other, this->y / other);
}

template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator/(const Vec2<U>& other) const {
  return Vec2<T>(this->x / other.x, this->y / other.y);
}

template<typename T>
Vec2<float> Vec2<T>::operator/(const Vec2<float>& other) const {
  return Vec2<float>(this->x / other.x, this->y / other.y);
}

template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator+(const Vec2<U>& other) const {
  return Vec2<T>(static_cast<T>(this->x + other.x), static_cast<T>(this->y + other.y));
}

template<typename T>
Vec2<float> Vec2<T>::operator+(const Vec2<float>& other) const {
  return Vec2<float>(this->x + other.x, this->y + other.y);
}

template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator-(const Vec2<U>& other) const {
  return Vec2<T>(static_cast<T>(this->x - other.x), static_cast<T>(this->y - other.y));
}

template<typename T>
Vec2<float> Vec2<T>::operator-(const Vec2<float>& other) const {
  return Vec2<float>(this->x - other.x, this->y - other.y);
}

template<typename T>
void Vec2<T>::operator*=(const Vec2<T>& other) {
  *this = *this * other;
}

template<typename T>
template<typename U>
void Vec2<T>::operator*=(const Vec2<U>& other) {
  *this = *this * other;
}

template<typename T>
void Vec2<T>::operator/=(const Vec2<T>& other) {
  *this = *this / other;
}

template<typename T>
template<typename U>
void Vec2<T>::operator/=(const Vec2<U>& other) {
  *this = *this / other;
}

template<typename T>
void Vec2<T>::operator+=(const Vec2<T>& other) {
  *this = *this + other;
}

template<typename T>
template<typename U>
void Vec2<T>::operator+=(const Vec2<U>& other) {
  *this = *this + other;
}

template<typename T>
void Vec2<T>::operator-=(const Vec2<T>& other) {
  *this = *this - other;
}

template<typename T>
template<typename U>
void Vec2<T>::operator-=(const Vec2<U>& other) {
  *this = *this - other;
}

template<typename T>
T Vec2<T>::dot(const Vec2<T>& other) const {
  return this->x * other.x + this->y * other.y;
}

template<typename T>
T Vec2<T>::det(const Vec2<T>& other) const {
  return this->x * other.y - this->y * other.x;
}

template<typename T>
template<typename N, typename D>
fraction<N,D> Vec2<T>::angle_between(const Vec2<T>& other) const {
  return Utility::atan2(this->det(other), this->dot(other));
}

template<typename T>
template<typename N, typename D>
fraction<N, D> Vec2<T>::magnitude() const {
  return Utility::sqrt(this->dot(*this));
}

template<typename T>
template<typename N, typename D>
Vec2<T> Vec2<T>::rotate(fraction<N, D> angle_radians) const {
  fraction<N, D> old_x = x;
  fraction<N, D> old_y = y;
  
  // Calculate Sine and Cosine of the angle once for efficiency
  fraction<N, D> cos_theta = Utility::cos(angle_radians, 2);
  fraction<N, D> sin_theta = Utility::sin(angle_radians, 2);

  // Apply the rotation formula
  return Vec2<T>(static_cast<T>(old_x * cos_theta - old_y * sin_theta), static_cast<T>(old_x * sin_theta + old_y * cos_theta));
}

template<typename T>
template<typename N, typename D>
Vec2<fraction<N, D>> Vec2<T>::project_onto(const Vec2<fraction<N, D>> & other) const {
  return (this->dot(other)/Utility::pow(other.magnitude(), 2))*other;
}

namespace Utility {
  template<typename T>
  Vec2<T> wrap_euler_angle(Vec2<T> euler_angles) {
    return Vec2<T>(wrap_euler_angle(euler_angles.x), wrap_euler_angle(euler_angles.y));
  }
};

// TYPE ALIASES

typedef Vec2<int16_t> Vec2I;
typedef Vec2<F16B> Vec2F16B;
typedef Vec2<F32B> Vec2F32B;
typedef Vec2<F64B> Vec2F64B;