#ifndef LIB_TEMPLATE
#include <iostream>
#include <string>
#endif

#ifndef TEST_UTIL
#define TEST_UTIL

#define eq(actual, expect) test::Equal(actual, expect, __LINE__, "")
#define eq2(actual, expect, msg) test::Equal(actual, expect, __LINE__, msg)

namespace test
{
using namespace std;

namespace color
{
string red(string msg) { return "\033[31m" + msg + "\033[m"; }
string green(string msg) { return "\033[32m" + msg + "\033[m"; }
string yellow(string msg) { return "\033[33m" + msg + "\033[m"; }
string cyan(string msg) { return "\033[36m" + msg + "\033[m"; }
}  // namespace color

int _successCnt = 0;
int _failedCnt = 0;
const string indent = "  ";

template <class T, class U, class V>
void Equal(T actual, U expect, int line, V msg = "") {
    if (actual != expect) {
        cout << indent + color::red("Failed")
             << " line: " << line
             << " (actual:" << actual << " / expect: " << expect << ")"
             << " " << msg << '\n';
        _failedCnt++;
    }
    else {
        _successCnt++;
    }
}

void Require(string msg) {
    cout << indent + color::yellow("[Test Require] ") + msg << '\n';
}

void Start(string name) {
    cout << color::cyan("> " + name) << '\n';
    _successCnt = 0;
    _failedCnt = 0;
}

void Finish() {
    cout << indent + color::green("[Pass] ") << _successCnt;
    if (_failedCnt) {
        cout << '\n'
             << indent + color::red("[Failed] ") << _failedCnt;
    }
    cout << endl;
}
}  // namespace test

#endif
