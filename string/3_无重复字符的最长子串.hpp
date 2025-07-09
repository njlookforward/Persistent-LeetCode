#ifndef LENGTHOFLONGESTSUBSTRING_HPP
#define LENGTHOFLONGESTSUBSTRING_HPP

#include <string>
using std::string;
#include <unordered_set>
using std::unordered_set;
#include <algorithm>
using std::max;

/**
 * @brief 需要找到给定字符串中无重复字符的最长子串，返回他的长度
 * @idea 1) 枚举出以字符串任意位置为右边界的无重复子串，找到最长的子串，返回长度
 * 2）数据结构：int left, right作为滑动窗口的左右边界；
 * unordered_set存储当前已遍历的滑动窗口的无重复字符集合
 * windowSize记录当前的滑动窗口大小
 * res记录最大的窗口大小
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        unordered_set<char> u_set;
        int curWindow = 0;
        int res = 0;
        for(int left = 0, right = 0; right < s.size(); ) {
            // while(right < s.size() && u_set.find(s[right]) == u_set.end()) {
            //     u_set.insert(s[right]);
            //     ++curWindow;
            //     res = max(res, curWindow);
            //     ++right;
            // }
            // while循环就是为了得到以s[right]为边界的无重复字符的子串
            while(left < right && u_set.find(s[right]) != u_set.end()) {
                u_set.erase(s[left]);
                --curWindow;
                ++left;
            }
            // 即使滑动窗口只剩下1，前面的都是重复的，且都已经在u_set中删除了，那么此时的s[right]就是不重复的，需要添加到u_set中
            // Bug1: 这里之前忘记写了，既然此时s[right]是无重复元素，需要将s[right]放进u_set中，然后更新滑动窗口
            u_set.insert(s[right]);
            ++curWindow;
            res = max(res, curWindow);
            ++right;
        }

        return res;
    }
};



#endif