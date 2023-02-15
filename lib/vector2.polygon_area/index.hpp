#pragma once

#include "../template/index.hpp"
#include "../vector2/index.hpp"

// 参考: https://imagingsolution.net/math/calc_n_point_area/

// [START]
long double polygonArea(const vector<Vector2>& vertices) {
    long double ret = 0;
    const int size = vertices.size();
    for (int i = 0; i < size - 1; i++) ret += vertices[i].cross(vertices[i + 1]);
    ret += vertices[size - 1].cross(vertices[0]);
    return abs(ret) / 2;
}
// [END]
