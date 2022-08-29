#ifndef LIB_TEMPLATE
#include "../template/index.cpp"
#endif

#ifndef LIB_SPARSE_TABLE
#define LIB_SPARSE_TABLE

// [START]
template <class T, const T& (*op)(const T&, const T&)>
struct SparseTable
{
    vector<vector<T>> _table;
    vector<int> _log2;

    SparseTable(const vector<T>& v) {
        const int n = v.size();
        _log2.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) _log2[i] = _log2[i >> 1] + 1;
        _table.assign(_log2[n] + 1, vector<T>(n));
        for (int i = 0; i < n; i++) _table[0][i] = v[i];
        for (int k = 1; k <= _log2[n]; k++) {
            for (int i = 0; i + (1 << k) <= n; i++)
                _table[k][i] = op(_table[k - 1][i], _table[k - 1][i + (1 << (k - 1))]);
        }
    }

    inline T get(const int& l, const int& r) const {
        const int ex = _log2[r - l];
        return op(_table[ex][l], _table[ex][r - (1 << ex)]);
    }
};
// [END]

#endif

/* https://atcoder.jp/contests/abc263/tasks/abc263_d
int main() {
    ll n, l, r; IN(n, l, r);
    vector<ll> a(n); IN(a);
    vector<ll> b(n+1); rep(i, 0, n) b[i+1] = b[i] + a[i];
    vector<ll> rr(n+1); rr[0] = r * n;
    rep(i, 0, n) {
        rr[i+1] = rr[i] - r + a[i];
    }
    SparseTable<ll, min> table(rr);
    ll ans = rr[n];
    rep(i, 0, n+1) {
        ll left = l * i;
        ll right = table.get(i, n+1) - (b[i] - b[0]);
        chmin(ans, left + right);
    }
    OUT(ans);
    return 0;
}
*/
