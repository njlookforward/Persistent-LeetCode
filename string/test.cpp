#include "kmp.hpp"
#include <iostream>
using std::cout, std::endl;

void testkmp()
{
    string haystack("sadbutsad"),
           needle("sad");
    // string haystack("leetcode"),
    //        needle("leeto");
    // int firstOccurIndex = Solution().strStr(haystack, needle);
    int firstOccurIndex = Solution_1().strStr(haystack, needle);
    cout << firstOccurIndex << endl;
}

int main()
{
    testkmp();

    return 0;
}