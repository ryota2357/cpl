#pragma once

#include "../template/index.hpp"

// [START]
#include <memory>
using namespace std;

template <class T, T (*op)(T, T), T e>
struct SegmentTree
{
    const int _originSize;
    int _size;
    shared_ptr<T[]> _data;

    SegmentTree(int size) : _originSize(size) { init_data_(); }
    SegmentTree(const vector<T>& vec) : _originSize(vec.size()) {
        init_data_();
        for (int i = 0; i < _originSize; ++i) {
            _data[i + _size] = vec[i];
        }
        for (int i = _size - 1; i >= 1; --i) {
            _data[i] = op(_data[2 * i + 1], _data[2 * i]);
        }
    }

    T query(const int l, const int r) const {
        assert(0 <= l && l <= r && r <= _size);
        int nl = l + _size;
        int nr = r + _size;
        T retl = e, retr = e;
        while (nl < nr) {
            if (nl & 1) {
                retl = op(retl, _data[nl]);
                nl += 1;
            }
            if (nr & 1) {
                nr -= 1;
                retr = op(retr, _data[nr]);
            }
            nl >>= 1;
            nr >>= 1;
        }
        return op(retl, retr);
    }

    class Index
    {
        const shared_ptr<T[]> data;
        const int pos;

      public:
        explicit Index(const shared_ptr<T[]> data_, const int index, const int size) : data(data_), pos(index + size) {}
        void operator=(const T value) {
            data[pos] = value;
            for (int i = (pos >> 1); i > 0; i >>= 1) {
                data[i] = op(data[2 * i], data[2 * i + 1]);
            }
        }
        operator T() const {
            return data[pos];
        }
    };

    Index operator[](const int index) const {
        assert((uint)index < (uint)_size);
        return Index(_data, index, _size);
    }

  private:
    void init_data_() {
        _size = 1;
        while (_originSize > _size) { _size <<= 1; }
        _data = make_shared_for_overwrite<T[]>(2 * _size);
        for (int i = 0; i < 2 * _size; ++i) {
            _data[i] = e;
        }
    }
};
// [END]
