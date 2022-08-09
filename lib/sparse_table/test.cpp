#include "index.cpp"
#include "../_test_util/util.cpp"

const string& f(const string& a, const string& b) {
    return a.length() < b.length() ? a : b;
};

int main() {
    test::Start("sparse_table");
    { /* min<int> */
        vector<int> a = {2, 3, 5, 4, 1, 6, 0};
        int n = a.size();
        SparseTable<int, min> table(a);
        eq(table.get(0, n), 0);
        eq(table.get(0, 3), 2);
        eq(table.get(1, 3), 3);
        eq(table.get(4, 6), 1);
        eq(table.get(5, 6), 6);
        eq(table.get(4, n), 0);
    }
    { /* max<int> */
        vector<int> a = {2, 3, 5, 4, 1, 6, 0};
        int n = a.size();
        SparseTable<int, max> table(a);
        eq(table.get(0, n), 6);
        eq(table.get(0, 2), 3);
        eq(table.get(1, 3), 5);
        eq(table.get(4, 5), 1);
        eq(table.get(5, 6), 6);
        eq(table.get(6, n), 0);
    }
    {
        vector<string> a = { "ab", "abc", "a", "abcde", "abcd" };
        int n = a.size();
        SparseTable<string, f> table(a);
        eq(table.get(0, n), "a");
        eq(table.get(0, 2), "ab");
        eq(table.get(3, 4), "abcde");
        eq(table.get(2, 5), "a");
        eq(table.get(4, n), "abcd");
    }
    test::Finish();
}
