#pragma once

#include "../template/index.hpp"

// [START]
struct PrimeSieve
{
    const uint _max_num;
    vector<int> sieve, primes;
    PrimeSieve(const int max_num = 1) : _max_num(max(1, max_num)), sieve(max(2, max_num + 1)) {
        sieve[0] = sieve[1] = -1;
        primes.emplace_back(2);
        for (int i = 2; i <= max_num; i += 2) sieve[i] = 2;
        for (ll i = 3; i <= max_num; i += 2) {
            if (sieve[i]) continue;
            primes.emplace_back(i);
            sieve[i] = i;
            for (ll j = i * i; j <= max_num; j += i)
                if (!sieve[j]) sieve[j] = i;
        }
    }
    inline bool isPrime(const int& x) const {
        assert((uint)x <= _max_num);
        return sieve[x] == x;
    }
    vector<int> factorize(int x) const {
        assert((uint)x <= _max_num);
        vector<int> ret;
        if (x < 2) return ret;
        while (x != 1) {
            ret.emplace_back(sieve[x]);
            x /= sieve[x];
        }
        return ret;
    }
    int divisorCount(int x) const {
        assert((uint)x <= _max_num);
        if (x == 0) return 0;
        int cnt = 1, ret = 1;
        while (x != 1) {
            const int b = sieve[x];
            x /= sieve[x];
            const int p = sieve[x];
            if (b == p) cnt++;
            else ret *= (cnt + 1), cnt = 1;
        }
        ret *= cnt;
        return ret;
    }
    vector<int> divisors(const int x) const {
        assert((uint)x <= _max_num);
        if (x == 0) return {};
        auto fac = factorize(x);
        vector<int> ret = {1};
        for (const int& f : fac) {
            int s = ret.size();
            for (int i = 0; i < s; i++) ret.emplace_back(ret[i] * f);
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
// [END]
