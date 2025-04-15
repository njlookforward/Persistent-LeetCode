#ifndef RESTORE_IP_ADDRESS_HPP
#define RESTORE_IP_ADDRESS_HPP

#include <string>
using std::string; using std::stoi;

#include <vector>
using std::vector;

class Solution {
public:
    bool isValid(const string &s, int beg, int end) {
        if(end > beg && s[beg] == '0')
            return false;
        int num = stoi(s.substr(beg, end - beg + 1));
        if(num < 0 || num > 255)
            return false;  
        return true;
    }
    void backTracking(const string &s, int startIdx, int k, string &ip, vector<string> &result) {
        if(k == 4) {
            if(startIdx == s.size())
                // key:一定要注意不能包含最后的'.'
                result.emplace_back(ip.begin(), ip.end()-1);
            return;
        }
        // BUG: for循环中的终止条件不完整，没有考虑到可能超出字符串的序列
        for(int i = startIdx; i < startIdx + 3 && i < s.size(); ++i) {
            if(isValid(s, startIdx, i)) {
                string sub = s.substr(startIdx, i - startIdx + 1);
                ip += sub;
                ip += '.';
            } else 
                continue;
            backTracking(s, i + 1, k + 1, ip, result);
            ip.erase(ip.end() - 1 - (i - startIdx + 1), ip.end());
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string> result;
        if(s.size() < 4 || s.size() > 12)
            return result;
        backTracking(s, 0, 0, ip, result);
        return result;
    }
};

class Solution_carl {
public:
    bool isValid(const string &s, int beg, int end) {
        if(beg > end)
            return false;
        if(beg != end && s[beg] == '0')
            return false;
        int num = 0;
        for (int i = beg; i <= end; i++)
        {
            if(s[i] < '0' || s[i] > '9')
                return false;
            num = num * 10 + s[i] - '0';
            if(num > 255)
                return false;   
        }
        return true;
    }
    void backTracking(string &s, int startIdx, int pointNum, vector<string> &result)
    {
        if(pointNum == 3) {
            if(isValid(s, startIdx, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for(int i = startIdx; i < s.size(); ++i) {
            if(isValid(s, startIdx, i)) {
                s.insert(s.begin() + i + 1, '.');
                backTracking(s, i + 2, pointNum + 1, result);
                s.erase(s.begin() + i + 1);
            } else  break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.size() < 4 || s.size() > 12)
            return result;
        backTracking(s, 0, 0, result);
        return result;
    }
};

#endif