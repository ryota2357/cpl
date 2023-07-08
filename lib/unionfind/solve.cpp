/*
 * Library Checker - Unionfind
 * https://judge.yosupo.jp/problem/unionfind
*/

#include "index.hpp"

int main() {
    int n, q; IN(n, q);
    UnionFind uf(n);
    while (q--) {
        int t, u, v; IN(t, u, v);
        if (t == 0) {
            uf.unite(u, v);
        } else {
            if (uf.same(u, v)) {
                OUT(1);
            } else {
                OUT(0);
            }
        }
    }
    return 0;
}
