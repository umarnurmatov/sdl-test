#include "mymath.h"

template<typename T>
float distance(Vec2<T> &v1, Vec2<T> &v2) { return std::sqrt(std::pow(v1.x + v2.x, 2) + std::pow(v1.y + v2.y, 2)); }

template<typename T>
float dot_product(Vec2<T> v1, Vec2<T> v2) { return v1.x * v2.x + v1.y * v2.y; }

template<typename T>
float cross_product(const Vec2<T> &v1, const Vec2<T> &v2) { return v1.x * v2.y - v1.y * v2.x; }

template<typename T>
Vec2<T> cross_product( const Vec2<T>& a, float s ) { return Vec2<T>( s * a.y, -s * a.x ); }

template<typename T>
Vec2<T> cross_product( float s, const Vec2<T>& a ) { return Vec2<T>( -s * a.y, s * a.x ); }

template<typename T>
Vec2<T> max(Vec2<T> &v1, Vec2<T> &v2) { return Vec2<T>(std::max(v1.x, v2.x), std::max(v1.y, v2.y)); }


float clamp(float min, float max, float a)
{
  if (a < min) return min;
  if (a > max) return max;
  return a;
}

float degree_to_radians(float deg) { return deg * PI / 180.f; }

bool is_equal_with_precision_up_to_epsilon(float a, float b) { return std::abs( a - b ) <= EPSILON; }