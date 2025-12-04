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

  template<typename U>
  friend Vec3<T> operator*(const U& lhs, const Vec3<T>& rhs) {
    return rhs * lhs;
  }

  template<typename U>
  Vec3<T> operator*(const Vec3<U>& other) const;

  Vec3<float> operator*(const Vec3<float>& other) const;

  template<typename U>
  Vec3<T> operator/(const U& other) const;

  template<typename U>
  friend Vec3<T> operator/(const U& lhs, const Vec3<T>& rhs) {
    return rhs / lhs;
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

  float magnitude() const;

  Vec3 rotate(const Vec3<float> & euler_angles_radians) const;

  Vec3<float> project_onto(const Vec3<float> & other) const;

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
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
template<typename U>
void Vec3<T>::operator*=(const Vec3<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
void Vec3<T>::operator/=(const Vec3<T>& other) {
  auto res = *this / other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
template<typename U>
void Vec3<T>::operator/=(const Vec3<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
void Vec3<T>::operator+=(const Vec3<T>& other) {
  auto res = *this + other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
template<typename U>
void Vec3<T>::operator+=(const Vec3<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
void Vec3<T>::operator-=(const Vec3<T>& other) {
  auto res = *this - other;
  x = res.x;
  y = res.y;
  z = res.z;
}

template<typename T>
template<typename U>
void Vec3<T>::operator-=(const Vec3<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
  z = res.z;
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
float Vec3<T>::magnitude() const {
  return sqrtf(static_cast<float>(this->dot(*this)));
}

template<typename T>
Vec3<T> Vec3<T>::rotate(const Vec3<float> & euler_angles_radians) const {
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

  // Return a new Vec3<T> with the rotated coordinates, cast back to T
  return Vec3<T>(
      static_cast<T>(px),
      static_cast<T>(py),
      static_cast<T>(pz)
  );
}

template<typename T>
Vec3<float> Vec3<T>::project_onto(const Vec3<float> & other) const {
  return (this->dot(other)/pow(other.magnitude(), 2))*other;
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
typedef Vec3<float> Vec3F;