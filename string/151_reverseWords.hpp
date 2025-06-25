#ifndef REVERSEWORDS_HPP
#define REVERSEWORDS_HPP

#include <utility>
using std::swap;

#include <string>
using std::string;

class Solution {
public:
    void reverse(string &str, int start, int end);
    void removeExtraSpaces(string &str);

    // 翻转所有的字符串
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        // 将每个单词进行翻转
        int start = 0;
        for(int i = 0; i <= s.size(); i++) {
            if(i == s.size() || s[i] == ' ') {
                reverse(s, start, i-1);
                start = i+1;
            }
        } 

        return s;
    }
};

void Solution::reverse(string &str, int start, int end) {
    // 左闭右闭区间
    for(int i = start, j = end; i < j; i++, j--) {
        swap(str[i], str[j]);
    }
}

void Solution::removeExtraSpaces(string &str) {
    // 我需要删除所有的空格，然后遇到新的单词，自己加上新的空格
    int slow = 0;
    for(int i = 0; i < str.size(); i++) {
        // 遇到非空格才处理
        if(str[i] != ' ') {
            if(slow != 0 ) str[slow++] = ' ';
            while (i < str.size() && str[i] != ' ')
            {
                str[slow++] = str[i++];
            }
        }
    }
    str.resize(slow);
}



#endif