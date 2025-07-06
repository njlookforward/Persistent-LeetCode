#include "76_最小覆盖子串_self.hpp"
#include <iostream>
using std::cout; using std::endl;

void test_min_cover_substr() {
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "aa";
    string t = "aa";

    string resSubstr = Solution().minWindow(s, t);

    cout << "最终的结果是" << resSubstr << endl;
}

int main(void) {
    test_min_cover_substr();

    return 0;
}