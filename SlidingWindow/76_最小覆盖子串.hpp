#ifndef MINWINDOW_HPP
#define MINWINDOW_HPP

#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <climits>

class Solution {

public:

    string minWindow(string s, string t) {

        //先判断一下s 和 t的长度,

        //他们中任何一个长度为0 都需要返回空字符串

        if(s.length() == 0 || t.length() == 0){

            return "";

        }

        //定义两个哈希表 一个哈希表统计T的频率

        //另一个哈希表 统计T中元素在s中(滑动窗口中)出现的频率

        unordered_map<char,int> u_mapT;

        unordered_map<char,int> u_mapW;

        //首先统计一下T中字符的频率

        for(int i=0;i<t.length();i++){

            u_mapT[t[i]]++;

        }

        //统计一下T对应哈希表中 元素的个数

        int tCount = u_mapT.size();

        //have变量统计 滑动窗中的t字符的变量个数？？

        int have = 0;

        //定义结果字符串的起点

        //结果字符串的长度 初始化为最大的int值

        int resStart = 0, resLen = INT_MAX;

        //滑动窗左右边界都初始化为0

        int left = 0,right = 0;

        //如果right对应的字符存在于T中 那就统计一下 字符中的频率

        while(right<s.length()){

            if(u_mapT.count(s[right])){

                u_mapW[s[right]]++;

                //同时去判断 当前窗口中字符的频率和T中这个字符的频率是否相等

                //如果相等 说明有一个字符满足条件，需要更新have字符

                if(u_mapT[s[right]] == u_mapW[s[right]]){

                    have++;

                }

            }

            //看一下这两个是否相等 如果相等

            //说明当前窗口符合条件 需要更新当先窗口的起点和长度

            while(have == tCount){

                //如果当前窗口的长度<之前记录的最小长度 则更新最小值

                if(right-left+1<resLen){

                    resLen = right - left + 1;

                    resStart = left;

                }

                //窗口满足条件的话 我们需要移动窗口的左边界

                //去枚举以下一个元素为左边界的 符合条件的窗口

                //移动之前我们需要更新left指针对应的元素在哈希表中的频率和have的值

                //当前元素在T中 我们才需要去更新

                if(u_mapT.count(s[left])){

                    u_mapW[s[left]]--;

                    if(u_mapT[s[left]]>u_mapW[s[left]]){

                        --have;

                    }

                }

                ++left;

            }

            //直到当前窗口不满足条件 我们就需要移动right指针

            ++right;

        }

        //如果我们没有找到最小的长度  返回空字符串

        if(resLen == INT_MAX) return"";

        return s.substr(resStart,resLen);

    }

};


#endif