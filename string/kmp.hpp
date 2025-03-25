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

void Solution_1::getNext(int *next, string s)
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

int Solution_1::strStr(string haystack, string needle)
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