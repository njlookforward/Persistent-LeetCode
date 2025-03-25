#ifndef KMP_HPP
#define KMP_HPP
#include <string>
using std::string;

class Solution {
public:
    void getNext(int *next, string str);
    int strStr(string haystack, string needle);
};

// next数组的作用就是当当前字符不匹配时，让模式串中的指针根据next数组回到最大相等前后缀的下一个位置
// 我先不玩花活呢，先按照KMP算法的核心思想进行实现
inline void Solution::getNext(int *next, string str)
{
    // 仍然是三步走战略：1 初始化next数组   2 当前后缀不相等时处理  3 当前后缀相等时处理
    int j = 0;  // 代表前缀的末尾字符位置，同事代表最大相等前后缀长度
    next[0] = j;
    for(int i = 1; i < str.size(); ++i)
    {
        while (j > 0 && str[i] != str[j])
        {
            j = next[j - 1];
        }

        if(str[i] == str[j])
        {
            ++j;
        }
        // Bug：对于没有匹配的字符的next[]也要进行赋值
        next[i] = j;
    }
}

inline int Solution::strStr(string haystack, string needle)
{
    int next[needle.size()];
    getNext(next, needle);
    int j = 0;
    for(int i = 0; i < haystack.size(); ++i)
    {
        while (j > 0 && haystack[i] != needle[j])
        {
            j = next[j - 1];
        }
        if(haystack[i] == needle[j])
            ++j;
        // Bug: 他妹的==写成了=
        if(j == needle.size())
            return i - needle.size() + 1;
    }
    return -1;
}

class Solution_1 {
public:
    void getNext(int *next, string s);
    int strStr(string haystack, string needle);
};

inline void Solution_1::getNext(int *next, string s)
{
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); ++i)
    {
        while (j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if(s[i] == s[j + 1])
            ++j;
        next[i] = j;
    }
}

inline int Solution_1::strStr(string haystack, string needle)
{
    if(needle.size() == 0)
        return -1;  // 需要先进行判断是否合法

    int next[needle.size()];
    getNext(next, needle);
    int j = -1;
    for(int i = 0; i < haystack.size(); ++i)
    {
        while (j >= 0 && haystack[i] != needle[j+1])
        {
            j = next[j];
        }
        if(haystack[i] == needle[j + 1])
            ++j;
        if(j == needle.size() - 1)
            return i - needle.size() + 1;
    }
    return -1;
}

// next数组的作用是记录不同位置字符出现不同时，如何进行回退，从前面匹配的子字符串中的某个位置继续比较
class kmp_norm {
public:
    void getNext(int *next, const string &s);       // 针对的是模式串得到next数组
    int strStr(string haystack, string needle);
};

// 不管是getNext还是strStr都是在移动模式串（getNext中是前缀串）去尝试匹配下一个字符
inline void kmp_norm::getNext(int *next, const string &s)
{
    int j = 0;  // 正常情况下，从index0开始进行比对
    next[0] = j;    // 初始化next数组
    for(int i = 1; i < s.size(); ++i)
    {
        // i必须从1开始进行比较
        while (j > 0 && s[i] != s[j])
        {
            // 一旦前缀串与后缀串不同，那么就不停的向前回退，直到找到与后缀串末尾字符相同的位置为止或者移动到了开头位置
            j = next[j - 1];
        }
        if(s[i] == s[j])
            ++j;    // j不仅仅代表前缀串的末尾字符位置，而且表示最大相同前后缀子串长度
        next[i] = j;
    }
}

inline int kmp_norm::strStr(string haystack, string needle)
{
    if(needle.size() == 0)
        return -1;

    int next[needle.size()];
    getNext(next, needle);
    int j = 0;
    for(int i = 0; i < haystack.size(); ++i)
    {
        while (j > 0 && haystack[i] != needle[j])
        {
            // 只要不相等，就一直向前回退，不断的移动模式串，而不需要移动文本串
            j = next[j - 1];    // 从前一个已经成功匹配的模式子串查找回退位置
        }
        if(haystack[i] == needle[j])
            ++j;
        if(j == needle.size())
            return i - needle.size() + 1;
    }
    return -1;
}

class kmp_1 {
public:
    void getNext(int *next, const string &s);
    int strStr(string haystack, string needle);
};

inline void kmp_1::getNext(int *next, const string &s)
{
    // 将next数组从正常值减1，这样容易得到next[]回退子串的索引
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); ++i)
    {
        // 前后缀子串不匹配，相当于内部的一种kmp查找
        while (j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if(s[i] == s[j + 1])
            ++j;
        next[i] = j;
    }
}

inline int kmp_1::strStr(string haystack, string needle)
{
    if(needle.size() == 0)
        return -1;

    int next[needle.size()];
    getNext(next, needle);
    int j = -1;
    for(int i = 0; i < haystack.size(); ++i)
    {
        while (j >= 0 && haystack[i] != needle[j + 1])
        {
            j = next[j];
        }
        if(haystack[i] == needle[j + 1])    // bug
            ++j;
        if(j == needle.size() - 1)
            return i - needle.size() + 1;
    }
    return -1;
}

#endif