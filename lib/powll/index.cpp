#include "../template/index.cpp"

#ifndef LIB_POWLL
#define LIB_POWLL

ll powll(ll x, ll n) {
    ll ret = 1;
    while(n > 0) {
        if(n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

#endif
