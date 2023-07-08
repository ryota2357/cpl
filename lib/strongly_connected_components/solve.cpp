/*
 * Strongly Connected Components
 * https://judge.yosupo.jp/problem/scc
 */

#include "index.hpp"

int main() {
    int n, m; IN(n, m);
    vector g(n, vector<int>());
    rep(i, 0, m) {
        int a, b; IN(a, b);
        g[a].push_back(b);
    }
    StronglyConnectedComponents scc(g);
    auto s = scc.get();
    OUT(s.size());
    each(t, s) {
        cout << t.size();
        each(u, t) {
            cout << ' ' << u;
        }
        cout << '\n';
    }
    return 0;
}
