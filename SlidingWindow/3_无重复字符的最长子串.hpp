#ifndef __LENGTHOF_LONGESTSUBSTRING_HPP__
#define __LENGTHPF_LONGESTSUBSTRING_HPP__

#include <string>
using std::string;
#include <unordered_set>
using std::unordered_set;
#include <algorithm>
using std::max;

/**
 * @beirf:
 * set<char> 保存已浏览的无重复字符
 * left, right 左右窗口边界
 * result结果
 * curWindow 当前窗口大小
 */
class Solution {
public:
    int lengthOfLongestSubstrin(string s) {
        int result = 0;
        int curWindow = 0;
        unordered_set<char> char_set;
        for(int left = 0, right = 0; right < s.size(); ++right) {
            while (left < right && char_set.find(s[right]) != char_set.end())
            {
                char_set.erase(s[left]);
                curWindow--;
                left++;
            }
            char_set.insert(s[right]);
            ++curWindow;
            result = max(curWindow, result);
        }
        return result;
    }
};

#endif