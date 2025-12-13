#pragma once

#include "utility.h"

#include <stdint.h>
#include <math.h>

// VEC3

template<typename T> struct Vec3 {
  Vec3(T x = static_cast<T>(0), T y = static_cast<T>(0), T z = static_cast<T>(0));
  Vec3(const Vec3 & other);

  T x, y, z;

  template<typename U>
  Vec3<T> operator*(const U& other) const;

  friend Vec3<T> operator*(const uint8_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }
  
  friend Vec3<T> operator*(const uint16_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }
  
  friend Vec3<T> operator*(const uint32_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }

  friend Vec3<T> operator*(const int8_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }
  
  friend Vec3<T> operator*(const int16_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }

  friend Vec3<T> operator*(const int32_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }

  template<typename N, typename D>
  friend Vec3<T> operator*(const fraction<N, D>& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
  }

  template<typename U>
  Vec3<T> operator*(const Vec3<U>& other) const;

  Vec3<float> operator*(const Vec3<float>& other) const;

  template<typename U>
  Vec3<T> operator/(const U& other) const;

  friend Vec3<T> operator/(const uint8_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }
  
  friend Vec3<T> operator/(const uint16_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }
  
  friend Vec3<T> operator/(const uint32_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }

  friend Vec3<T> operator/(const int8_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }
  
  friend Vec3<T> operator/(const int16_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }

  friend Vec3<T> operator/(const int32_t& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }

  template<typename N, typename D>
  friend Vec3<T> operator/(const fraction<N, D>& lhs, const Vec3<T>& rhs) {
      return Vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
  }

  template<typename U>
  Vec3<T> operator/(const Vec3<U>& other) const;

  Vec3<float> operator/(const Vec3<float>& other) const;
  
  template<typename U>
  Vec3<T> operator+(const Vec3<U>& other) const;
  
  Vec3<float> operator+(const Vec3<float>& other) const;

  template<typename U>
  Vec3<T> operator-(const Vec3<U>& other) const;

  Vec3<float> operator-(const Vec3<float>& other) const;

  void operator*=(const Vec3& other);

  template<typename U>
  void operator*=(const Vec3<U>& other);

  void operator/=(const Vec3& other);
  
  template<typename U>
  void operator/=(const Vec3<U>& other);
  
  void operator+=(const Vec3& other);

  template<typename U>
  void operator+=(const Vec3<U>& other);

  void operator-=(const Vec3& other);

  template<typename U>
  void operator-=(const Vec3<U>& other);

  T dot(const Vec3& other) const;

  float angle_between(const Vec3& other) const;

  template<typename N, typename D>
  fraction<N, D> magnitude() const;

  template<typename N, typename D>
  Vec3<T> rotate(const Vec3<fraction<N, D>>& euler_angles_radians) const;

  template<typename N, typename D>
  Vec3<fraction<N, D>> project_onto(const Vec3<fraction<N, D>> & other) const;

};

template<typename T>
Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

template<typename T>
Vec3<T>::Vec3(const Vec3 & other) : x(other.x), y(other.y), z(other.z) {}

template<typename T>
template<typename U>
Vec3<T> Vec3<T>::operator*(const U& other) const {
  return Vec3<T>(this->x * other, this->y * other, this->z * other);
}

template<typename T>
template<typename U>
Vec3<T> Vec3<T>::operator*(const Vec3<U>& other) const {
  return Vec3<T>(this->x * other.x, this->y * other.y, this->z * other.z);
}

template<typename T>
Vec3<float> Vec3<T>::operator*(const Vec3<float>& other) const {
  return Vec3<float>(this->x * other.x, this->y * other.y, this->z * other.z);
}

template<typename T>
template<typename U>
Vec3<T> Vec3<T>::operator/(const U& other) const {
  return Vec3<T>(this->x / other, this->y / other, this->z / other);
}

template<typename T>
template<typename U>
Vec3<T> Vec3<T>::operator/(const Vec3<U>& other) const {
  return Vec3<T>(this->x / other.x, this->y / other.y, this->z / other.z);
}

template<typename T>
Vec3<float> Vec3<T>::operator/(const Vec3<float>& other) const {
  return Vec3<float>(this->x / other.x, this->y / other.y, this->z / other.z);
}

template<typename T>
template<typename U>
Vec3<T> Vec3<T>::operator+(const Vec3<U>& other) const {
  return Vec3<T>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<typename T>
Vec3<float> Vec3<T>::operator+(const Vec3<float>& other) const {
  return Vec3<float>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<typename T>
template<typename U>
Vec3<T> Vec3<T>::operator-(const Vec3<U>& other) const {
  return Vec3<T>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template<typename T>
Vec3<float> Vec3<T>::operator-(const Vec3<float>& other) const {
  return Vec3<float>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template<typename T>
void Vec3<T>::operator*=(const Vec3<T>& other) {
  *this = *this * other;
}

template<typename T>
template<typename U>
void Vec3<T>::operator*=(const Vec3<U>& other) {
  *this = *this * other;
}

template<typename T>
void Vec3<T>::operator/=(const Vec3<T>& other) {
  *this = *this / other;
}

template<typename T>
template<typename U>
void Vec3<T>::operator/=(const Vec3<U>& other) {
  *this = *this * other;
}

template<typename T>
void Vec3<T>::operator+=(const Vec3<T>& other) {
  *this = *this + other;
}

template<typename T>
template<typename U>
void Vec3<T>::operator+=(const Vec3<U>& other) {
  *this = *this * other;
}

template<typename T>
void Vec3<T>::operator-=(const Vec3<T>& other) {
  *this = *this - other;
}

template<typename T>
template<typename U>
void Vec3<T>::operator-=(const Vec3<U>& other) {
  *this = *this * other;
}

template<typename T>
T Vec3<T>::dot(const Vec3<T>& other) const {
  return this->x * other.x + this->y * other.y + this->z * other.z;
}

template<typename T>
float Vec3<T>::angle_between(const Vec3<T>& other) const {
  return acosf(this->dot(other) / (this->magnitude() * other.magnitude()));
}

template<typename T>
template<typename N, typename D>
fraction<N, D> Vec3<T>::magnitude() const {
  return Utility::sqrt(this->dot(*this));
}

template<typename T>
template<typename N, typename D>
Vec3<T> Vec3<T>::rotate(const Vec3<fraction<N, D>>& euler_angles_radians) const {
    // Convert fraction angles to T
    T rx = static_cast<T>(euler_angles_radians.x);
    T ry = static_cast<T>(euler_angles_radians.y);
    T rz = static_cast<T>(euler_angles_radians.z);

    // Compute sin & cos for each axis
    T cx = Utility::cos(rx, 3);
    T sx = Utility::sin(rx, 3);

    T cy = Utility::cos(ry, 3);
    T sy = Utility::sin(ry, 3);

    T cz = Utility::cos(rz, 3);
    T sz = Utility::sin(rz, 3);

    // Rotation matrices:
    // Rz * Ry * Rx applied to vector v

    // Step 1: rotate around X
    T x1 =  x;
    T y1 =  y * cx - z * sx;
    T z1 =  y * sx + z * cx;

    // Step 2: rotate around Y
    T x2 =  x1 * cy + z1 * sy;
    T y2 =  y1;
    T z2 = -x1 * sy + z1 * cy;

    // Step 3: rotate around Z
    T x3 = x2 * cz - y2 * sz;
    T y3 = x2 * sz + y2 * cz;
    T z3 = z2;

    return Vec3<T>(x3, y3, z3);
}

template<typename T>
template<typename N, typename D>
Vec3<fraction<N, D>> Vec3<T>::project_onto(const Vec3<fraction<N, D>> & other) const {
  return (this->dot(other)/Utility::pow(other.magnitude(), 2))*other;
}

namespace Utility {
  template<typename T>
  Vec3<T> wrap_euler_angle(Vec3<T> euler_angles) {
    return Vec3<T>(wrap_euler_angle(euler_angles.x), wrap_euler_angle(euler_angles.y), wrap_euler_angle(euler_angles.z));
  }
};

// TYPE ALIASES

typedef Vec3<int16_t> Vec3I16B;
typedef Vec3<int8_t> Vec3I8B;
typedef Vec3<fraction<int8_t, int8_t>> Vec3F16B;