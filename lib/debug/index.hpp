#pragma once
#include "../template/index.hpp"

// [START]
namespace debug
{
void _DEBUG_PRINT_() {
    static bool done = false;
    if (done) return;
    done = true;
    std::cout << "\033[33m[Debug Mode]\033[m" << std::endl;
}
void Write(void) {
    _DEBUG_PRINT_();
    std::cerr << std::endl;
}
template <class T, class U>
void Write(const std::pair<T, U>& p) {
    _DEBUG_PRINT_();
    std::cerr << ' ' << '{' << p.first << ',' << p.second << '}' << std::endl;
}
template <class T>
void Write(const std::set<T>& V) {
    _DEBUG_PRINT_();
    std::cerr << " {";
    for (const auto& v : V) std::cerr << ' ' << v;
    std::cerr << " }" << std::endl;
}
template <class T>
void Write(const std::vector<T>& V, int n = -1) {
    _DEBUG_PRINT_();
    if (n < 0) n = V.size();
    std::cerr << " [";
    for (int i = 0; i < n; ++i) std::cerr << ' ' << V[i];
    std::cerr << " ]" << std::endl;
}
template <class T, class U>
void Write(const std::vector<std::pair<T, U>>& V, int n = -1) {
    _DEBUG_PRINT_();
    if (n < 0) n = V.size();
    std::cerr << " [";
    for (int i = 0; i < n; ++i) std::cerr << " {" << V[i].first << ',' << V[i].second << '}';
    std::cerr << " ]" << std::endl;
}
template <class T, class... U>
void Write(const T& t, const U&... u) {
    _DEBUG_PRINT_();
    std::cerr << ' ' << t;
    Write(u...);
}
}  // namespace debug
using namespace debug;
// [END]
