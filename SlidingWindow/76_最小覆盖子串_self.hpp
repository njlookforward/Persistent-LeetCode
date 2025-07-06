#ifndef MIN_COVER_SUBSTR_HPP
#define MIN_COVER_SUBSTR_HPP

#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <climits>

/**
 * @brief 使用滑动窗口的方法，
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if(s_len == 0 || t_len == 0) {
            return "";
        }

        unordered_map<char, int> u_mapT;
        for(int i = 0; i < t_len; i++) {
            u_mapT[t[i]]++;
        }

        int left = 0, right = 0;
        int resStart = 0, minLength = INT_MAX;
        int tInWindow = 0;
        int tCount = u_mapT.size();
        unordered_map<char, int> u_mapWindow;
        while(right < s_len) {
            // 当没有找到全部字符的时候，需要右移右边界
            u_mapWindow[s[right]]++;
            if(u_mapT.count(s[right]) && u_mapWindow[s[right]] == u_mapT[s[right]]) {
                ++tInWindow;
            }

            // bug2: 最小子串中可能有重复元素，因此需要使用的是u_mapT的长度，而不是t的长度
            while(tInWindow == tCount) {
                int curLength = right - left + 1;
                if(curLength < minLength) {
                    resStart = left;
                    minLength = curLength;
                }

                u_mapWindow[s[left]]--;
                if(u_mapT.count(s[left]) && u_mapWindow[s[left]] < u_mapT[s[left]]) {
                    tInWindow--;
                }
                // Bug1: 滑动窗口都是向右移的
                ++left;
            }
            ++right;
        }

        if(minLength == INT_MAX) return "";

        return s.substr(resStart, minLength);
    }
};



#endif