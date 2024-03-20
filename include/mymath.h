#pragma once
#include <cmath>
#include <iostream>

const float PI = 3.14159265358979323f;
const float EPSILON = 1e-3;
const float G_EARTH_SURFACE = 9.81f;

float degree_to_radians(float deg);

template<typename T>
struct Vec2
{
    T x;
    T y;

    Vec2(T _x, T _y) { x = _x; y = _y; }

    Vec2() { x = y = 0; }

    void set(T _x, T _y) { x = _x; y = _y; }

    Vec2 operator+(Vec2 v2)
    {
        Vec2 v_temp;
        v_temp.x = x + v2.x;
        v_temp.y = y + v2.y;
        return v_temp;
    }
    void operator+=(Vec2<T> v2) { x += v2.x; y += v2.y; }

    Vec2<T> operator-(Vec2<T> &v2) const
    {
        Vec2<T> v_temp;
        v_temp.x = x - v2.x;
        v_temp.y = y - v2.y;
        return v_temp;
    }
    void operator-=(Vec2<T> v2) { x -= v2.x; y -= v2.y; }

    bool operator==(Vec2<T> &v2) const { return (x == v2.x) && (y == v2.y); }
    bool operator==(const Vec2<T> &v2) const { return (x == v2.x) && (y == v2.y); } 

    // Умножение вектора на число
    Vec2<T> operator*(T a)
    {
        Vec2 v_temp;
        v_temp.x = x * a;
        v_temp.y = y * a;
        return v_temp;
    }

    // Деление вектора на число
    Vec2<T> operator/(T a)
    {
        Vec2<T> v_temp;
        v_temp.x = x / a;
        v_temp.y = y / a;
        return v_temp;
    }

    // Умножение вектора на число
    void operator*=(T a) { x *= a; y *= a; }
    
    // Деление вектора на число
    void operator/=(T a) { x /= a; y /= a; }

    Vec2<T> operator=(Vec2<T> v2) { x = v2.x; y = v2.y; return *this; }
    Vec2<T> operator-() const { return Vec2<T>(-x, -y); }


    T len() const { return std::sqrt( x * x + y * y ); }
    T lenSquare() const { return x * x + y * y; }

    Vec2<T> normalized() const { return *this * (1 / this->len()); }
    Vec2<T> perpendicular() const { return Vec2<T>(-y, x); }

    void print() { std::cout << x << " " << y << std::endl; }
};


typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

template<typename T>
T distance(Vec2<T> &v1, Vec2<T> &v2);

// Скалярное произведение
template<typename T>
float dot_product(Vec2<T> v1, Vec2<T> v2);

// Векторное произведение; возвращает длину вектора, который по сути параллелен оси z
template<typename T>
float cross_product(const Vec2<T> &v1, const Vec2<T> &v2);

// Более экзотичные (но необходимые) виды векторных произведений
// с вектором a и скаляром s, оба возвращают вектор
template<typename T>
Vec2<T> cross_product(const Vec2<T>& a, float s);

template<typename T>
Vec2<T> cross_product(float s, const Vec2<T>& a);

template<typename T>
Vec2<T> max(Vec2<T> &v1, Vec2<T> &v2);

template<typename T>
bool is_equal_with_precision_up_to_epsilon(float a, float b);

// Ограничение числа от min до max
// a < min ? min : a или a > max ? max : a
float clamp(float min, float max, float a);

// Ортогональная матрица трансформации
template<typename T>
struct Mat22
{
    float m00, m01;
    float m10, m11;
    Mat22(float angle) { set_angle(angle); }
    Mat22(float _m00, float _m01, float _m10, float _m11) { m00 = _m00; m01 = _m01; m10 = _m10; m11 = _m11; } 

    void set_angle(float radians)
    {
        float _cos = std::cos(radians), _sin = std::sin(radians);
        m00 = _cos; m01 = -_sin;
        m10 = _sin; m11 = _cos;
    }

    // получение транспонированной матрицы
    Mat22 transpose() { return Mat22(m00, m10, m01, m11); }

    // поворот вектора при помощи текущей матрицы трансформации
    Vec2<T> rotate_vector(Vec2<T> &v) { return Vec2<T>(m00 * v.x + m01 * v.y, m10 * v.x + m11 * v.y); }
    
};

template<typename T>
struct Rect
{
    T left, top, width, height;

    Rect()
        : left   { (T)0 },
          top    { (T)0 },
          width  { (T)0 },
          height { (T)0 }
    {
    }

    Rect(T _l, T _t, T _w, T _h)
        : left   { _l },
          top    { _t },
          width  { _w },
          height { _h }
    {
    }

    Rect(Vec2<T> pos, Vec2<T> size)
        : left   { pos.x },
          top    { pos.y },
          width  { size.x },
          height { size.y }
    {
    }
};

typedef Rect<int>   IntRect;
typedef Rect<float> FloatRect;