#include "index.hpp"
#include "../_test_util/util.cpp"

int main() {
    test::Start("topological_sort");
    {
        vector<vector<int>> a = {
            {5},
            {4},
            {1, 0},
            {0, 5},
            {0},
            {6},
            {}
        };
        vector<int> ret = topologicalSort(a);
        // 3,2,1,4,0,5,6,7 も ok
        vector<int> expect = {2, 3, 1, 4, 0, 5, 6, 7};
        rep(i, 0, 7) {
            eq(ret[i], expect[i]);
        }
    }
    {
        vector<vector<int>> a = {
            {1},
            {2},
            {0},
        };
        vector<int> ret = topologicalSort(a);
        eq(ret.size(), 0);
    }
    test::Finish();
}

/* https://atcoder.jp/contests/abc216/tasks/abc216_d
int main() {
    int n, m; IN(n, m);
    vector a(m, vector<int>());
    rep(i, 0, m) {
        int k = read();
        rep(_, 0, k) a[i].push_back(read() - 1);
    }
    vector g(n, vector<int>());
    rep(i, 0, m) {
        rep(j, 1, a[i].size()) {
            g[a[i][j-1]].push_back(a[i][j]);
        }
    }
    OUT(topologicalSort(g).size() == n ? "Yes" : "No");
    return 0;
}
*/
