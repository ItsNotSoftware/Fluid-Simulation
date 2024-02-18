#ifndef VEC2_HPP
#define VEC2_HPP

#include "common.hpp"

class Vec2 {
   public:
    f32 x;
    f32 y;

    Vec2(f32 x, f32 y);

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(f32 scalar) const;
    Vec2 operator/(f32 scalar) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(f32 scalar);
    Vec2& operator/=(f32 scalar);

   private:
};

#endif