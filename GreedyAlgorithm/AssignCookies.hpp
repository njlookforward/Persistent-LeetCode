#ifndef ASSIGN_COOKIES_HPP
#define ASSIGN_COOKIES_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0,
            i= 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if(s[j] >= g[i]) {
                ++result;
                ++i; ++j;
            } else {
                ++j;
            }
        }
        return result;
    }
};

#endif