#include "vec2.hpp"

Vec2::Vec2(f32 x, f32 y) : x(x), y(y) {}

Vec2 Vec2::operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
Vec2 Vec2::operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
Vec2 Vec2::operator*(f32 scalar) const { return Vec2(x * scalar, y * scalar); }
Vec2 Vec2::operator/(f32 scalar) const { return Vec2(x / scalar, y / scalar); }

Vec2& Vec2::operator+=(const Vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(f32 scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(f32 scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
