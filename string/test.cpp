// #include "kmp.hpp"
#include "repeated_substring_pattern.hpp"
#include <iostream>
using std::cout, std::endl;

// void testkmp()
// {
//     // string haystack("sadbutsad"),
//     //        needle("sad");
//     string haystack("leetcode"),
//            needle("leeto");
//     // int firstOccurIndex = Solution().strStr(haystack, needle);
//     int firstOccurIndex = kmp_1().strStr(haystack, needle);
//     cout << firstOccurIndex << endl;
// }

void test_repeatedSubstringPattern()
{
    string s("aa");
    // string s("abab");
    // string s("aba");
    // string s("abcabcabcabc");
    cout << std::boolalpha << Solution_1().repeatedSubstringPattern(s) << endl;
}

int main()
{
    // testkmp();
    test_repeatedSubstringPattern();

    return 0;
}