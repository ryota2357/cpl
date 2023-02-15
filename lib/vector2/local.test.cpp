#include "../_test_util/util.cpp"
#include "index.hpp"

#define eqv(actual, expectX, expectY) \
    eq2(sgn((actual).x - (long double)expectX), 0, "x actual: " + to_string((actual).x) + " expect: " + to_string(expectX)); \
    eq2(sgn((actual).y - (long double)expectY), 0, "y actual: " + to_string((actual).y) + " expect: " + to_string(expectY))

int main() {
    test::Start("vector2");
    { /* sgn */
        long double a = 0.00000000001;
        eq(sgn(a) == 0, true);
        eq(sgn(-a) == 0, true);

        long double b = 0.000000001;
        eq(sgn(b) == 0, false);
        eq(sgn(b) > 0, true);
        eq(sgn(-b) == 0, false);
        eq(sgn(-b) < 0, true);

        long double c = 1.00000000002;
        long double d = 1.000000000021;
        eq(sgn(c - d), 0);
    }
    { /* construct */
        Vector2 a; eqv(a, 0, 0);
        Vector2 b(123.456789, 987654.321); eqv(b, 123.456789, 987654.321);
        Vector2 c(-123.456789, -987654.321); eqv(c, -123.456789, -987654.321);
        Vector2 d = {112233.445566, 998877.665544}; eqv(d, 112233.445566, 998877.665544);
    }
    { /* add */
        Vector2 a = {2, 7};
        Vector2 b = {3, 5};
        eqv(a + b, 5, 12);
        a += b; eqv(a, 5, 12);
        b += a; eqv(b, 8, 17);
    }
    { /* sub */
        Vector2 a = {5, -2};
        Vector2 b = {-3, 7};
        eqv(a - b, 8, -9);
        a -= b; eqv(a, 8, -9);
        b -= a; eqv(b, -11, 16);
    }
    { /* mul */
        Vector2 a = {-3, 7};
        eqv(2 * a, -6, 14);
        eqv(-1.1 * a, 3.3, -7.7);
        eqv(a * -3, 9, -21);
        eqv(a * -0.4, 1.2, -2.8);

        a *= 3;
        eqv(a, -9, 21);
    }
    { /* div */
        Vector2 a = {12, -6};
        eqv(a / 4, 3, -1.5);
        eqv(a / -0.1, -120, 60);

        a /= 2;
        eqv(a, 6, -3);
    }
    { /* equal */
        Vector2 a = {1, 3};
        Vector2 b = {1, 3};
        eq(a == b, true);

        Vector2 c = {2.0002, -2.006};
        Vector2 d = {-1.0001, 1.003};
        eq(c != d, true);
        eq(c == -2*d, true);
    }
    { /* dot */
        test::Require("dot()");
    }
    { /* cross */
        test::Require("cross()");
    }
    { /* sqrMagnitude */
        test::Require("sqrMagnitude()");
    }
    { /* magnitude */
        test::Require("magnitude()");
    }
    { /* angle */
        test::Require("angle()");
    }
    { /* rotation */
        test::Require("rotation()");
    }
    test::Finish();
}
