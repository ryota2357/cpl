#include "index.cpp"
#include "../_test_util/util.cpp"

using mint = ModInt<1000000007>;

int main() {
    test::Start("modint");
    { /* construct */
        mint a; eq(a.value, 0);
        mint b = 1000000007; eq(b.value, 0);
        mint c = 10; eq(c.value, 10);
        mint d = -1; eq(d.value, 1000000006);
    }
    { /* equal */
        mint a; eq(a, a.value);
        mint b = -1; eq(b, b.value);
    }
    { /* add */
        mint a = 10; a += 1000000006; eq(a, 9);
        mint b = 10; eq(b + 1000000006, 9);
        mint c = 10; c += 10; eq(c, 20);
        mint d = 10; eq(d + 10, 20);
        mint e = 1000000006; eq(++e, 0);
        mint f = 1000000006; eq(f++, 1000000006); eq(f, 0);
        mint g = 1; eq(++g, 2);
        mint h = 1; eq(h++, 1); eq(h, 2);
    }
    { /* sub */
        mint a = 10; a -= 12; eq(a, 1000000005);
        mint b = 10; eq((b - 12), 1000000005);
        mint c = 20; c -= 10; eq(c, 10);
        mint d = 20; eq(d - 10, 10);
        mint e = 0; eq(--e, 1000000006);
        mint f = 0; eq(f--, 0); eq(f, 1000000006);
        mint g = 1; eq(--g, 0);
        mint h = 1; eq(h--, 1); eq(h, 0);
        mint i = 1; eq(-i, 1000000006);
    }
    { /* mul */
        mint a = 126; a *= 7936508; eq(a, 1);
        mint b = 126; eq(b * 7936508, 1);
        mint c = 20; c *= 10; eq(c, 200);
        mint d = 20; eq(d * 10, 200);
    }
    { /* div */
        test::Require("div()");
    }
    { /* pow */
        test::Require("pow()");
    }
    { /* inv */
        test::Require("inv()");
    }
    test::Finish();
}
