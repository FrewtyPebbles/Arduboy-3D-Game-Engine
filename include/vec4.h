#pragma once

#include "utility.h"
#include "fraction.h"

#include <stdint.h>
#include <math.h>

// Vec4

template<typename T> struct Vec4 {
  Vec4(T x = static_cast<T>(0), T y = static_cast<T>(0), T z = static_cast<T>(0), T w = static_cast<T>(0));
  Vec4(const Vec4 & other);

  T x, y, z, w;

  template<typename U>
  Vec4<T> operator*(const U& other) const;

  template<typename U>
  friend Vec4<T> operator*(const U& lhs, const Vec4<T>& rhs) {
    return rhs * lhs;
  }

  template<typename U>
  Vec4<T> operator*(const Vec4<U>& other) const;

  Vec4<float> operator*(const Vec4<float>& other) const;

  template<typename U>
  Vec4<T> operator/(const U& other) const;

  template<typename U>
  friend Vec4<T> operator/(const U& lhs, const Vec4<T>& rhs) {
    return rhs / lhs;
  }

  template<typename U>
  Vec4<T> operator/(const Vec4<U>& other) const;

  Vec4<float> operator/(const Vec4<float>& other) const;
  
  template<typename U>
  Vec4<T> operator+(const Vec4<U>& other) const;
  
  Vec4<float> operator+(const Vec4<float>& other) const;

  template<typename U>
  Vec4<T> operator-(const Vec4<U>& other) const;

  Vec4<float> operator-(const Vec4<float>& other) const;

  void operator*=(const Vec4& other);

  template<typename U>
  void operator*=(const Vec4<U>& other);

  void operator/=(const Vec4& other);
  
  template<typename U>
  void operator/=(const Vec4<U>& other);
  
  void operator+=(const Vec4& other);

  template<typename U>
  void operator+=(const Vec4<U>& other);

  void operator-=(const Vec4& other);

  template<typename U>
  void operator-=(const Vec4<U>& other);

  T dot(const Vec4& other) const;

  float angle_between(const Vec4& other) const;

  float magnitude() const;

  Vec4 rotate(const Vec4<float> & euler_angles_radians) const;

  Vec4<float> project_onto(const Vec4<float> & other) const;

};

template<typename T>
Vec4<T>::Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

template<typename T>
Vec4<T>::Vec4(const Vec4 & other) : x(other.x), y(other.y), z(other.z) {}

template<typename T>
template<typename U>
Vec4<T> Vec4<T>::operator*(const U& other) const {
  return Vec4<T>(this->x * other, this->y * other, this->z * other, this->w * other);
}

template<typename T>
template<typename U>
Vec4<T> Vec4<T>::operator*(const Vec4<U>& other) const {
  return Vec4<T>(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
}

template<typename T>
Vec4<float> Vec4<T>::operator*(const Vec4<float>& other) const {
  return Vec4<float>(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
}

template<typename T>
template<typename U>
Vec4<T> Vec4<T>::operator/(const U& other) const {
  return Vec4<T>(this->x / other, this->y / other, this->z / other, this->w / other);
}

template<typename T>
template<typename U>
Vec4<T> Vec4<T>::operator/(const Vec4<U>& other) const {
  return Vec4<T>(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
}

template<typename T>
Vec4<float> Vec4<T>::operator/(const Vec4<float>& other) const {
  return Vec4<float>(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
}

template<typename T>
template<typename U>
Vec4<T> Vec4<T>::operator+(const Vec4<U>& other) const {
  return Vec4<T>(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other);
}

template<typename T>
Vec4<float> Vec4<T>::operator+(const Vec4<float>& other) const {
  return Vec4<float>(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

template<typename T>
template<typename U>
Vec4<T> Vec4<T>::operator-(const Vec4<U>& other) const {
  return Vec4<T>(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

template<typename T>
Vec4<float> Vec4<T>::operator-(const Vec4<float>& other) const {
  return Vec4<float>(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

template<typename T>
void Vec4<T>::operator*=(const Vec4<T>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
template<typename U>
void Vec4<T>::operator*=(const Vec4<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
void Vec4<T>::operator/=(const Vec4<T>& other) {
  auto res = *this / other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
template<typename U>
void Vec4<T>::operator/=(const Vec4<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
void Vec4<T>::operator+=(const Vec4<T>& other) {
  auto res = *this + other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
template<typename U>
void Vec4<T>::operator+=(const Vec4<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
void Vec4<T>::operator-=(const Vec4<T>& other) {
  auto res = *this - other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
template<typename U>
void Vec4<T>::operator-=(const Vec4<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
  w = res.w;
}

template<typename T>
T Vec4<T>::dot(const Vec4<T>& other) const {
  return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
}

template<typename T>
float Vec4<T>::angle_between(const Vec4<T>& other) const {
  return acosf(this->dot(other) / (this->magnitude() * other.magnitude()));
}

template<typename T>
float Vec4<T>::magnitude() const {
  return sqrtf(static_cast<float>(this->dot(*this)));
}

template<typename T>
Vec4<T> Vec4<T>::rotate(const Vec4<float> & euler_angles_radians) const {
  float yaw = euler_angles_radians.z;
  float pitch = euler_angles_radians.x;
  float roll = euler_angles_radians.y;

  float cx = cosf(pitch);
  float sx = sinf(pitch);
  float cy = cosf(roll);
  float sy = sinf(roll);
  float cz = cosf(yaw);
  float sz = sinf(yaw);
  
  // Store the original vector values in floats for calculation
  float px = static_cast<float>(this->x);
  float py = static_cast<float>(this->y);
  float pz = static_cast<float>(this->z);

  // Apply Z rotation (Yaw)
  float tempX = px * cz - py * sz;
  float tempY = px * sz + py * cz;
  px = tempX;
  py = tempY;
  // pz remains unchanged in Z rotation

  // Apply X rotation (Pitch)
  tempY = py * cx - pz * sx;
  float tempZ = py * sx + pz * cx;
  py = tempY;
  pz = tempZ;
  // px remains unchanged in X rotation

  // Apply Y rotation (Roll)
  tempX = px * cy + pz * sy;
  tempZ = -px * sy + pz * cy;
  px = tempX;
  pz = tempZ;
  // py remains unchanged in Y rotation

  // Return a new Vec4<T> with the rotated coordinates, cast back to T
  return Vec4<T>(
      static_cast<T>(px),
      static_cast<T>(py),
      static_cast<T>(pz)
  );
}

template<typename T>
Vec4<float> Vec4<T>::project_onto(const Vec4<float> & other) const {
  return (this->dot(other)/pow(other.magnitude(), 2))*other;
}

namespace Utility{
  template<typename T>
  Vec4<T> wrap_euler_angle(Vec4<T> euler_angles) {
    return Vec4<T>(wrap_euler_angle(euler_angles.x), wrap_euler_angle(euler_angles.y), wrap_euler_angle(euler_angles.z), wrap_euler_angle(euler_angles.w));
  }
};

// TYPE ALIASES

typedef Vec4<int16_t> Vec4I16B;
typedef Vec4<int8_t> Vec4I8B;
typedef Vec4<fraction<int8_t, int8_t>> Vec4F16B;
