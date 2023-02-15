#include "index.hpp"
#include "../_test_util/util.cpp"

int main() {
    test::Start("prime_sieve");
    const int n = 1000000;
    { /* isPram */
        PrimeSieve seive(n);
        const auto sqrtJudge = [&](int x){
            if(x == 2) return true;
            if (x < 2 || x % 2 == 0) return false;
            for(ll i = 3; i*i <= x; i += 2) {
                if(x%i) continue;
                return false;
            }
            return true;
        };
        rep(i, 0, n) eq2(seive.isPrime(i), sqrtJudge(i), i);
    }
    { /* factorize */
        PrimeSieve seive(n);
        const auto sqrtJudge = [&](int x) {
            vector<int> ret;
            if(x < 2) return ret;
            while(x % 2 == 0) {
                ret.emplace_back(2);
                x /= 2;
            }
            for(ll i = 3; i * i <= n; i += 2) {
                while(x % i == 0) {
                    ret.emplace_back(i);
                    x /= i;
                }
            }
            if(x != 1) ret.emplace_back(x);
            return ret;
        };
        rep(i, 0, n) eq2(seive.factorize(i), sqrtJudge(i), i);
    }
    { /* divisors */
        PrimeSieve seive(n);
        const auto sqrtJudge = [&](int x) {
            vector<int> ret;
            if(x == 0) return ret;
            for(ll i = 1; i * i <= x; i++) {
                if(x % i) continue;
                ret.push_back(i);
                if (x / i != i) ret.push_back(x / i);
            }
            Sort(ret);
            return ret;
        };
        rep(i, 0, n) eq2(seive.divisors(i), sqrtJudge(i), i);
    }
    { /* divisorCount */
        PrimeSieve seive(n);
        rep(i, 0, n) eq2(seive.divisorCount(i), seive.divisors(i).size(), i);
    }
    test::Finish();
}
