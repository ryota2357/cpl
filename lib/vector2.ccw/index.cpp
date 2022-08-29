#ifndef LIB_TEMPLATE
#include "../template/index.cpp"
#endif

#ifndef LIB_VECTOR2
#include "../vector2/index.cpp"
#endif

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

/* https://atcoder.jp/contests/abc266/tasks/abc266_c
int main() {
    vector<Vector2> v(4); IN(v);
    rep(i, 0, 4) {
        if(ccw(v[i], v[(i+1)%4], v[(i+2)%4]) == -1) {
            OUT("No");
            return 0;
        }
    }
    OUT("Yes");
    return 0;
}
*/
