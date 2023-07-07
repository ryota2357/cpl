/*
 * ABC263 D - Left Right Operation
 * https://atcoder.jp/contests/abc263/tasks/abc263_d
 */

#include "index.hpp"

int main() {
    ll n, l, r; IN(n, l, r);
    vector<ll> a(n); IN(a);
    vector<ll> b(n + 1);
    rep (i, 0, n) {
        b[i + 1] = b[i] + a[i];
    }
    vector<ll> rr(n + 1);
    rr[0] = r * n;
    rep (i, 0, n) {
        rr[i + 1] = rr[i] - r + a[i];
    }
    SparseTable<ll, min> table(rr);
    ll ans = rr[n];
    rep (i, 0, n + 1) {
        ll left = l * i;
        ll right = table.get(i, n + 1) - (b[i] - b[0]);
        chmin(ans, left + right);
    }
    OUT(ans);
    return 0;
}
