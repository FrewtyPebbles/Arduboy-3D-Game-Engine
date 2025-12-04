#include <stdint.h>
#pragma once

#include <math.h>

// VEC2

template<typename T> struct Vec2 {
  Vec2(T x = static_cast<T>(0), T y = static_cast<T>(0));
  template<typename U>
  Vec2<T>(const Vec2<U> & other);

  T x, y;

  template<typename U>
  Vec2<T> operator*(const U& other) const;

  template<typename U>
  friend Vec2<T> operator*(const U& lhs, const Vec2<T>& rhs) {
    return rhs * lhs;
  }

  template<typename U>
  Vec2<T> operator*(const Vec2<U>& other) const;

  Vec2<float> operator*(const Vec2<float>& other) const;

  template<typename U>
  Vec2<T> operator/(const U& other) const;

  template<typename U>
  friend Vec2<T> operator/(const U& lhs, const Vec2<T>& rhs) {
    return rhs / lhs;
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

  float angle_between(const Vec2& other) const;

  float magnitude() const;

  Vec2 rotate(const float & angle_radians) const;

  Vec2<float> project_onto(const Vec2<float> & other) const;

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
  return Vec2<T>(this->x * other.x, this->y * other.y);
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
  return Vec2<T>(this->x + other.x, this->y + other.y);
}

template<typename T>
Vec2<float> Vec2<T>::operator+(const Vec2<float>& other) const {
  return Vec2<float>(this->x + other.x, this->y + other.y);
}

template<typename T>
template<typename U>
Vec2<T> Vec2<T>::operator-(const Vec2<U>& other) const {
  return Vec2<T>(this->x - other.x, this->y - other.y);
}

template<typename T>
Vec2<float> Vec2<T>::operator-(const Vec2<float>& other) const {
  return Vec2<float>(this->x - other.x, this->y - other.y);
}

template<typename T>
void Vec2<T>::operator*=(const Vec2<T>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
}

template<typename T>
template<typename U>
void Vec2<T>::operator*=(const Vec2<U>& other) {
  auto res = *this * other;
  x = res.x;
  y = res.y;
}

template<typename T>
void Vec2<T>::operator/=(const Vec2<T>& other) {
  auto res = *this / other;
  x = res.x;
  y = res.y;
}

template<typename T>
template<typename U>
void Vec2<T>::operator/=(const Vec2<U>& other) {
  auto res = *this / other;
  x = res.x;
  y = res.y;
}

template<typename T>
void Vec2<T>::operator+=(const Vec2<T>& other) {
  auto res = *this + other;
  x = res.x;
  y = res.y;
}

template<typename T>
template<typename U>
void Vec2<T>::operator+=(const Vec2<U>& other) {
  auto res = *this + other;
  x = res.x;
  y = res.y;
}

template<typename T>
void Vec2<T>::operator-=(const Vec2<T>& other) {
  auto res = *this - other;
  x = res.x;
  y = res.y;
}

template<typename T>
template<typename U>
void Vec2<T>::operator-=(const Vec2<U>& other) {
  auto res = *this - other;
  x = res.x;
  y = res.y;
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
float Vec2<T>::angle_between(const Vec2<T>& other) const {
  return atan2f(this->det(other), this->dot(other));
}

template<typename T>
float Vec2<T>::magnitude() const {
  return sqrtf(static_cast<float>(this->dot(*this)));
}

template<typename T>
Vec2<T> Vec2<T>::rotate(const float & angle_radians) const {
  float old_x = x;
  float old_y = y;
  
  // Calculate Sine and Cosine of the angle once for efficiency
  float cos_theta = cos(angle_radians);
  float sin_theta = sin(angle_radians);

  // Apply the rotation formula
  return Vec2<T>(old_x * cos_theta - old_y * sin_theta, old_x * sin_theta + old_y * cos_theta);
}

template<typename T>
Vec2<float> Vec2<T>::project_onto(const Vec2<float> & other) const {
  return (this->dot(other)/pow(other.magnitude(), 2))*other;
}

// TYPE ALIASES

typedef Vec2<int16_t> Vec2I;
typedef Vec2<float> Vec2F;


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

// TYPE ALIASES

typedef Vec3<int16_t> Vec3I16B;
typedef Vec3<int8_t> Vec3I8B;
typedef Vec3<float> Vec3F;