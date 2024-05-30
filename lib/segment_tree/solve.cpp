/*
 * Point Add Range Sum
 * https://judge.yosupo.jp/problem/point_add_range_sum
 */

#include "index.hpp"

ll f(ll a, ll b) {
    return a + b;
}

int main() {
    int n, q; IN(n, q);
    auto tree = SegmentTree<ll, f, 0>(n);
    rep (i, 0, n) {
        tree[i] = read();
    }
    while (q--) {
        int id = read();
        if (id == 0) {
            int p, x; IN(p, x);
            tree[p] = tree[p] + x;
        } else {
            int l, r; IN(l, r);
            OUT(tree.query(l, r));
        }
    }
}
