#pragma once

#include "../template/index.hpp"

// [START]
ll powll(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}
// [END]
