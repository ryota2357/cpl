#include "../_test_util/util.cpp"
#include "index.cpp"

int main() {
    test::Start("vector2.ccw");
    { /* 1 = ab -> Left  -> bc */
        Vector2 a = {1, 1};
        Vector2 b = {2, 0};
        Vector2 c = {3, 3};
        eq(ccw(a, b, c), 1);
    }
    { /* -1 = ab -> Right -> bc */
        Vector2 a = {0, 0};
        Vector2 b = {0, 1};
        Vector2 c = {1, 2};
        eq(ccw(a, b, c), -1);
    }
    { /* 2 = a -- b -- c */
        Vector2 a = {1, 2};
        Vector2 b = {3, 4};
        Vector2 c = {4, 5};
        eq(ccw(a, b, c), 2);

        Vector2 d = {0, 0};
        Vector2 e = {-1, 0};
        Vector2 f = {-100, 0};
        eq(ccw(d, e, f), 2);

        Vector2 g = {-1, -5};
        Vector2 h = {-1, 7};
        Vector2 i = {-1, 8};
        eq(ccw(g, h, i), 2);
    }
    { /* 0 = a -- c -- b */
        Vector2 a = {5, -4};
        Vector2 c = {3, -5};
        Vector2 b = {-1, -7};
        eq(ccw(a, b, c), 0);

        Vector2 d = {0, 9};
        Vector2 f = {1, 9};
        Vector2 e = {10, 9};
        eq(ccw(d, e, f), 0);

        Vector2 g = {1, 5};
        Vector2 i = {1, 7};
        Vector2 h = {1, 8};
        eq(ccw(g, h, i), 0);
    }
    { /* -2 = b -- a -- c */
        Vector2 b = {5, 2};
        Vector2 a = {3, 3};
        Vector2 c = {1, 4};
        eq(ccw(a, b, c), -2);

        Vector2 e = {-2, 2};
        Vector2 d = {1, 2};
        Vector2 f = {20, 2};
        eq(ccw(d, e, f), -2);

        Vector2 h = {2, -5};
        Vector2 g = {2, -7};
        Vector2 i = {2, -8};
        eq(ccw(g, h, i), -2);
    }
    test::Finish();
}

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
