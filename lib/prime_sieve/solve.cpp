/*
 * N回、素数判定, 素因数分解, 約数列挙 を行う
 *
 * 入力:
 * N, M
 * A_1, A_2, ..., A_N
 *
 * 制約:
 * 1 <= N <= 1e8
 * 1 <= A_i <= M <= N
 *
 * 出力:
 * [素数なら1, 素数でないなら0] [素因数分解した結果]
 * [約数の数] [約数列挙した結果]
 *
 * tests/generator/prime_sieve.cpp
 */

#include "index.hpp"

int main() {
    int n, m; IN(n, m);
    PrimeSieve ps(m);
    rep(i, 0, n) {
        int a = read();

        cout << ps.isPrime(a) << ' ';
        auto f = ps.factorize(a);
        each(x, f) cout << x << ' ';
        cout << '\n';

        cout << ps.divisorCount(a) << ' ';
        auto d = ps.divisors(a);
        each(x, d) cout << x << ' ';
        cout << '\n';
    }
}
