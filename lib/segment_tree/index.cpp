#include "../template/index.cpp"

#ifndef LIB_SEGMENT_TREE
#define LIB_SEGMENT_TREE

// [START]
template <class T, T (*op)(T, T), T e>
struct SegmentTree
{
    int _originSize, _size, _log2;
    vector<T> _data;
    SegmentTree(int size) : SegmentTree(vector<T>(size, e)) {}
    SegmentTree(const vector<T>& vec) : _originSize(vec.size()), _size(1), _log2(1) {
        while (_originSize > 1 << _log2) {
            ++_log2;
        }
        _size <<= _log2;
        _data = vector<T>(2 * _size, e);
        for (int i = 0; i < _originSize; ++i) {
            _data[i + _size] = vec[i];
        }
        for (int i = _size - 1; i >= 1; --i) {
            _data[i] = op(_data[2 * i + 1], _data[2 * i]);
        }
    }

    void update(const int& index, const T value) {
        assert((uint)index < (uint)_size);
        int pos = index + _size;
        _data[pos] = value;
        for (int i = 1; i <= _log2; ++i) {
            int t = pos >> i;
            _data[t] = op(_data[2 * t + 1], _data[2 * t]);
        }
    }

    inline T get(const int& index) const {
        assert((uint)index < (uint)_size);
        return _data[index + _size];
    }

    T query(const int& l, const int& r) const {
        assert(0 <= l && l <= r && r <= _size);
        int nl = l + _size;
        int nr = r + _size;
        T retl = e, retr = e;
        while (nl < nr) {
            if (nl & 1) {
                retl = op(retl, _data[nl]);
                ++nl;
            }
            if (nr & 1) {
                --nr;
                retr = op(retr, _data[nr]);
            }
            nl >>= 1;
            nr >>= 1;
        }
        return op(retl, retr);
    }
};

// [END]

#endif
