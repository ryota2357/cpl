#include <vector>
#include "../_test_util/util.cpp"
#include "index.cpp"

#define eq_esp(actual, expect) \
    eq2(sgn(actual - expect), 0, "actual: " + to_string(actual) + " expect: " + to_string(expect))

// 使用ツール: https://keisan.casio.jp/exec/system/1377138797

int main() {
    test::Start("vector2.polygon_area");
    { /* 1, 2 */
        vector<Vector2> a = { {1, 1} };
        eq_esp(polygonArea(a), 0);

        vector<Vector2> b = {
            {1, 2}, {3, 4}
        };
        eq_esp(polygonArea(b), 0);

        vector<Vector2> c = {
            {1, 2}, {1, 2}
        };
        eq_esp(polygonArea(c), 0);
    }
    { /* 3 */
        vector<Vector2> a = {
            {3, 6}, {4, 3}, {2, 1}
        };
        eq_esp(polygonArea(a), 4);

        vector<Vector2> b = {
            {0.001, 0.111}, {0.312, 10.1}, {100, 1}
        };
        eq_esp(polygonArea(b), 499.306766);
    }
    { /* 4 */
        vector<Vector2> a = {
            {2, 1}, {4, 2}, {5, 6}, {3, 4}
        };
        eq_esp(polygonArea(a), 5.5);

        vector<Vector2> b = {
            {-2, 1}, {4, -2}, {-5, -6}, {3, 4}
        };
        eq_esp(polygonArea(b), 12.5);
    }
    { /* 5 */
        vector<Vector2> a = {
            {2, 1}, {4, 2}, {5, 6}, {3, 4}, {1, 5}
        };
        eq_esp(polygonArea(a), 9);

        vector<Vector2> b = {
            {0.1, 9}, {-1.2, 4}, {1, -3}, {-13, -1}, {9, 10.1}
        };
        eq_esp(polygonArea(b), 35.755);
    }
    { /* many */
        vector<Vector2> a = {
            {0.123, 34},
            {-123, 142},
            {12, 345},
            {23, -34},
            {43, 4.1},
            {-4.144, 0.00001},
            {12, 341},
            {-124, -111},
            {-0.00124, 0.123},
            {94, -1.1234},
            {-123, 1.1},
            {23, -34},
        };
        eq_esp(polygonArea(a), 1144.596868492);
    }
    test::Finish();
}
