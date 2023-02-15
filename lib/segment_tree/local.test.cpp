#include "index.hpp"
#include "../_test_util/util.cpp"

int int_min(int a, int b) {
    return min(a, b);
}

int int_max(int a, int b) {
    return max(a, b);
}

int main() {
    test::Start("segment_tree");
    { /* RMinQ */
                      // 0  1  2   3  4  5   6  7
        vector<int> a = {3, 5, 2, 11, 9, 1, 20, 8};
        auto tree = SegmentTree<int, int_min, INF>(a);
        eq(tree.query(1, 5), 2);
        eq(tree.query(0, 0), INF);
        eq(tree.query(6, 7), 20);
        tree.update(2, 3);
        eq(tree.query(1, 5), 3);
        tree.update(3, 12);
        eq(tree.query(1, 5), 3);
    }
    { /* RMaxQ */
                      // 0  1  2   3  4  5   6  7
        vector<int> a = {3, 5, 2, 11, 9, 1, 20, 8};
        auto tree = SegmentTree<int, int_max, -INF>(a);
        eq(tree.query(2, 6), 11);
        eq(tree.query(7, 7), -INF);
        tree.update(3, 11);
        eq(tree.query(2, 6), 11);
        tree.update(4, 12);
        eq(tree.query(2, 6), 12);
        tree.update(5, 3);
        eq(tree.query(2, 6), 12);
    }
    test::Finish();
}

/* https://judge.yosupo.jp/problem/point_add_range_sum (submission: https://judge.yosupo.jp/submission/110686)
ll f(ll a, ll b) {
    return a + b;
}

int main() {
    int N, Q; IN(N, Q);
    auto tree = SegmentTree<ll, f, 0>(N);
    rep(i, 0, N) tree.update(i, read());

    rep(_, 0, Q) {
        int id = read();
        if(id == 0) {
            int p, x; IN(p, x);
            tree.update(p, tree.get(p) + x);
        } else {
            int l, r; IN(l, r);
            OUT(tree.query(l, r));
        }
    }
}
*/

