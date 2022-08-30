#include "../_test_util/util.cpp"
#include "index.cpp"

int main() {
    test::Start("powll");
    {
        ll a = powll(-1, 2); eq(a, 1);
        ll b = powll(3, 16); eq(b, 43046721);
        ll c = powll(123, 0); eq(c, 1);
    }
    test::Finish();
}
