#ifndef LIB_TEMPLATE
#include "../template/index.cpp"
#endif

#ifndef LIB_UNIONFIND
#define LIB_UNIONFIND

// [START]
struct UnionFind
{
    vector<int> data;
    const uint __size;
    UnionFind(const int size = 0) noexcept : data(size, -1), __size(max(0, size)) {}
    inline int root(const int& x) {
        assert((uint)x < __size);
        if (data[x] < 0) return x;
        return data[x] = root(data[x]);
    }
    inline bool unite(const int& x, const int& y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return false;
        if (data[rx] > data[ry]) swap(rx, ry);
        data[rx] += data[ry];
        data[ry] = rx;
        return true;
    }
    inline bool same(const int& x, const int& y) { return root(x) == root(y); }
    inline int size(const int& x) { return -data[root(x)]; }
};
// [END]

#endif
