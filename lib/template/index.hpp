#pragma once

// [START]
/*{{{ author: ryota2357 */
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
namespace ryota2357
{
template <class T1, class T2>
inline std::istream& operator>>(std::istream& is, std::pair<T1, T2>& P) noexcept {
    return is >> P.first >> P.second;
}
template <class T>
inline std::istream& operator>>(std::istream& is, std::vector<T>& V) noexcept {
    for (auto& v : V) is >> v;
    return is;
}
template <class T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& V) noexcept {
    const auto n = V.size() - 1;
    for (int i = 0; i < n; ++i) os << V[i] << ' ';
    return os << V.back();
}

inline void IN(void) noexcept { return; }
template <class T, class... U>
inline void IN(T& t, U&... u) noexcept {
    std::cin >> t;
    IN(u...);
}

template <class T>
inline void OUT(const T& x) noexcept { std::cout << x << '\n'; }

template <class T>
inline bool chmax(T& a, const T& b) noexcept { return a < b ? a = b, true : false; }

template <class T>
inline bool chmin(T& a, const T& b) noexcept { return a > b ? a = b, true : false; }

template <class T = int>
inline T read(void) {
    T ret = 0;
    char c = getchar();
    while ((c < '0' || '9' < c) && c != '-') c = getchar();
    const bool f = (c == '-') && (c = getchar());
    while ('0' <= c && c <= '9') {
        ret = 10 * ret + c - '0';
        c = getchar();
    }
    return f ? -ret : ret;
}

template <class T>
inline T ceil_div(const T& a, const T& b) {
    assert(b != 0);
    return (a + (b - 1)) / b;
}

template <class T>
inline T max(const std::vector<T>& v) { return *max_element(v.begin(), v.end()); }

template <class T>
inline T min(const std::vector<T>& v) { return *min_element(v.begin(), v.end()); }
}  // namespace ryota2357

using ll = long long;
using pint = std::pair<int, int>;
#define rep(i, a, b) for (ll i = (a); i < ll(b); ++i)
#define repr(i, a, b) for (ll i = (a); i >= ll(b); --i)
#define each(x, v) for (auto& x : v)
#define All(x) (x).begin(), (x).end()
#define AllR(x) (x).rbegin(), (x).rend()
#define Sort(x) (sort((x).begin(), (x).end()))
#define SortR(x) (sort((x).rbegin(), (x).rend()))
#define Unique(x) (x.erase(unique((x).begin(), (x).end()), (x).end()))
#define Fill(v, n) (fill((v), (v) + sizeof(v) / sizeof(*(v)), (v)))
#define INF (1073741823)
#define INFL (2305843009213693951ll)
using namespace std;
using namespace ryota2357;
/*}}}*/
// [END]