#include "../template/index.cpp"
#include "../vector2/index.cpp"

#ifndef LIB_VECTOR2_CCW
#define LIB_VECTOR2_CCW

// 参考: https://sen-comp.hatenablog.com/entry/2020/03/12/145742#iSP3点の位置関係

// [START]
/**
 * Premise: Each point a, b, c is different
 * Returns: 1 = ab -> Left  -> bc
 *         -1 = ab -> Right -> bc
 *          2 = a -- b -- c
 *          0 = a -- c -- b
 *         -2 = b -- a -- c
 */
int ccw(const Vector2& a, const Vector2& b, const Vector2& c) {
    int flag = sgn((b - a).cross(c - a));
    if (flag == 1) return 1;
    if (flag == -1) return -1;
    if (sgn((b - a).dot(c - b)) > 0) return 2;
    if (sgn((a - b).dot(c - a)) > 0) return -2;
    return 0;
}
// [END]

#endif
