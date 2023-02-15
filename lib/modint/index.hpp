#pragma once

#include "../template/index.hpp"

// [START]
template <ll Modulus>
struct ModInt
{
    ll value;
    constexpr ModInt(const ll value = 0) noexcept : value((value % Modulus + Modulus) % Modulus) {}
    inline ModInt& operator+=(const ModInt& rhs) noexcept {
        if (value += rhs.value, value >= Modulus) value -= Modulus;
        return *this;
    }
    inline ModInt& operator-=(const ModInt& rhs) noexcept {
        if (value -= rhs.value, value < 0) value += Modulus;
        return *this;
    }
    inline ModInt& operator*=(const ModInt& rhs) noexcept {
        value = value * rhs.value % Modulus;
        return *this;
    }
    inline ModInt& operator/=(const ModInt& rhs) noexcept {
        value = value * inv(rhs.value).value % Modulus;
        return *this;
    }
    inline ModInt& operator++() noexcept {
        if (++value >= Modulus) value -= Modulus;
        return *this;
    }
    inline ModInt operator++(int) noexcept {
        ModInt t = value;
        if (++value >= Modulus) value -= Modulus;
        return t;
    }
    inline ModInt& operator--() noexcept {
        if (--value < 0) value += Modulus;
        return *this;
    }
    inline ModInt operator--(int) noexcept {
        ModInt t = value;
        if (--value < 0) value += Modulus;
        return t;
    }
    inline ModInt operator-() const noexcept { return (-value + Modulus) % Modulus; }
    inline ModInt inv(void) const { return inv(value); }
    ModInt inv(const ll& n) const {
        ll a = n, b = Modulus, u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u %= Modulus, u < 0) u += Modulus;
        return u;
    }
    ModInt pow(ll n) const {
        assert(0 <= n);
        if (!n) return 1;
        ModInt t = pow(n >> 1);
        t *= t;
        if (n & 1) t *= (*this);
        return t;
    }
    friend inline ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }
    friend inline ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }
    friend inline ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }
    friend inline ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }
    friend inline bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value == rhs.value; }
    friend inline bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.value != rhs.value; }
    friend inline istream& operator>>(istream& is, ModInt& x) noexcept {
        ll val;
        is >> val;
        x = val;
        return is;
    }
    friend inline ostream& operator<<(ostream& os, const ModInt& x) noexcept { return os << x.value; }
};
// [END]
