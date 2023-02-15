#include "index.hpp"
#include "../_test_util/util.cpp"

int main() {
    test::Start("unionfind");
    {
        UnionFind uf(2);
        eq(uf.same(0, 1), false);
        eq(uf.size(0), 1);
        eq(uf.size(1), 1);
        uf.unite(0, 1);
        eq(uf.same(0, 1), true);
        eq(uf.size(0), 2);
        eq(uf.size(1), 2);
    }
    {
        int n = 500000;
        UnionFind uf(n);
        for (int i = 0; i < n - 1; i++) {
            uf.unite(i, i + 1);
        }
        eq(uf.size(0), n);
    }
    {
        int n = 500000;
        UnionFind uf(n);
        for (int i = n - 2; i >= 0; i--) {
            uf.unite(i, i + 1);
        }
        eq(uf.size(0), n);
    }
    test::Finish();
}
