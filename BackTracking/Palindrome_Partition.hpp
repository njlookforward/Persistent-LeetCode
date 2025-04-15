#ifndef PALINDROME_PARTITION_HPP
#define PALINDROME_PARTITION_HPP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

class Solution {
public:
    bool isPalindrome(const string &s, size_t beg, size_t end) {
        for(size_t i = beg, j = end; i < j; ++i, --j) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    void backTracking(const string &s, int startIdx, vector<string> &path, 
                                            vector<vector<string>> &result)
    {
        if(startIdx >= s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = startIdx; i < s.size(); ++i) {
            // 切割的范围: [startIdx, i]
            if(isPalindrome(s, startIdx, i)) {
                path.push_back(s.substr(startIdx, i - startIdx + 1));
            } else 
                continue;
            backTracking(s, i + 1, path, result);
            path.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> result;
        backTracking(s, 0, path, result);
        return result;
    }
};


#endif