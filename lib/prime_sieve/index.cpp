#include "../template/index.cpp"

#ifndef LIB_PRIME_SIEVE
#define LIB_PRIME_SIEVE

// [START]
struct PrimeSieve
{
    const uint __size;
    vector<int> sieve, primes;
    PrimeSieve(const int n = 1) : __size(max(1, n)), sieve(max(2, n + 1)) {
        sieve[0] = sieve[1] = -1;
        primes.emplace_back(2);
        for (int i = 2; i <= n; i += 2) sieve[i] = 2;
        for (ll i = 3; i <= n; i += 2) {
            if (sieve[i]) continue;
            primes.emplace_back(i);
            sieve[i] = i;
            for (ll j = i * i; j <= n; j += i)
                if (!sieve[j]) sieve[j] = i;
        }
    }
    inline bool isPrime(const int& x) const {
        assert((uint)x <= __size);
        return sieve[x] == x;
    }
    vector<int> factorize(int x) const {
        assert((uint)x <= __size);
        vector<int> ret;
        if (x < 2) return ret;
        while (x != 1) {
            ret.emplace_back(sieve[x]);
            x /= sieve[x];
        }
        return ret;
    }
    int divisorCount(int x) const {
        assert((uint)x <= __size);
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
        assert((uint)x <= __size);
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

#endif
