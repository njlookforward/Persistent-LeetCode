// #include "kmp.hpp"
// #include "repeated_substring_pattern.hpp"
#include "3_无重复字符的最长子串.hpp"
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

// void test_repeatedSubstringPattern()
// {
//     string s("aa");
//     // string s("abab");
//     // string s("aba");
//     // string s("abcabcabcabc");
//     cout << std::boolalpha << Solution_1().repeatedSubstringPattern(s) << endl;
// }

void test_lengthOfLongestSubstrint() {
    string s = "aab";
    int length = Solution().lengthOfLongestSubstring(s);

    cout << "最大长度是" << length << endl;
}

int main()
{
    // testkmp();
    // test_repeatedSubstringPattern();
    test_lengthOfLongestSubstrint();

    return 0;
}