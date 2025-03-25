#ifndef REPEATED_SUBSTRING_PATTERN_HPP
#define REPEATED_SUBSTRING_PATTERN_HPP

#include <string>
using std::string;

class Solution {
public:
    void getNext(int *next, const string &s);
    bool repeatedSubstringPattern(string s);
};

inline void Solution::getNext(int *next, const string &s)
{
    int j = 0;
    next[0] = j;
    for(int i = 1; i < s.size(); ++i)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = next[j - 1];
        }
        if(s[i] == s[j])
            ++j;
        next[i] = j;
    }
}

inline bool Solution::repeatedSubstringPattern(string s)
{
    if(s.size() == 0)
        return false;
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    // 前者是不能等于自身，必须有两个及以上的子串
    if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        return true;
    else
        return false;
}

class Solution_1 {
public:
    void getNext(int *next, const string &s);
    bool repeatedSubstringPattern(string s);
};

inline void Solution_1::getNext(int *next, const string &s)
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

inline bool Solution_1::repeatedSubstringPattern(string s)
{
    if(s.size() == 0)
        return false;
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if(next[len - 1] >= 0 && len % (len - next[len - 1] - 1) == 0)
        return true;
    else   
        return false;
}

#endif  