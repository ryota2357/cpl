#pragma once

#include "../template/index.hpp"

// [START]
constexpr long double EPS = 0.00000000010;
inline int sgn(const long double value) { return (value < -EPS ? -1 : (value > EPS ? 1 : 0)); }
struct Vector2
{
    long double x, y;
    constexpr Vector2() : x(0), y(0) {}
    constexpr Vector2(const long double x, const long double y) noexcept : x(x), y(y) {}
    inline Vector2 operator+() const noexcept { return *this; }
    inline Vector2 operator-() const noexcept { return {-x, -y}; }
    inline Vector2 operator+(const Vector2& other) const noexcept { return {x + other.x, y + other.y}; }
    inline Vector2 operator-(const Vector2& other) const noexcept { return {x - other.x, y - other.y}; }
    inline Vector2 operator*(const long double s) const noexcept { return {x * s, y * s}; }
    inline Vector2 operator/(const long double s) const noexcept { return {x / s, y / s}; }
    inline Vector2& operator+=(const Vector2& other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }
    inline Vector2& operator-=(const Vector2& other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    inline Vector2& operator*=(const long double s) noexcept {
        x *= s;
        y *= s;
        return *this;
    }
    inline Vector2& operator/=(const long double s) noexcept {
        x /= s;
        y /= s;
        return *this;
    }
    friend inline Vector2 operator*(const long double s, const Vector2& v) noexcept { return {s * v.x, s * v.y}; }
    friend inline istream& operator>>(istream& is, Vector2& v) noexcept { return is >> v.x >> v.y; }
    friend inline bool operator==(const Vector2& lhs, const Vector2& rhs) noexcept { return sgn(lhs.x - rhs.x) == 0 && sgn(lhs.y - rhs.y) == 0; }
    friend inline bool operator!=(const Vector2& lhs, const Vector2& rhs) noexcept { return !(lhs == rhs); }
    inline long double dot(const Vector2& other) const noexcept { return x * other.x + y * other.y; }
    inline long double cross(const Vector2& other) const noexcept { return x * other.y - y * other.x; }
    inline long double sqrMagnitude() const { return dot(*this); }
    inline long double magnitude() const { return sqrt(sqrMagnitude()); }
    inline long double angle() const { return atan2(y, x); }
    inline Vector2 rotation(const long double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }
};
// [END]
