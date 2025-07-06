#ifndef GROUP_ANAGRAMS_HPP
#define GROUP_ANAGRAMS_HPP

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;
#include <unordered_map>
using std::unordered_map;


/**
 * @brief 字母异位词进行分组，需要按照什么共同的特点进行分组
 * 仅仅只是字母异序，但是是由相同的字母构成的，因此抓住这个特点
 * 使用排序法加上哈希表可以将具有相同字母构成的单词放在一个键值对中
 * 
 * @note
 * time: 0(nklogk) 约等于0(n)，因为k是最长的单词长度，klogk约等于是一个常数，因此为0(n)
 * space: 哈希表的长度0(n)
 */
class Solution_sort {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result;
        if(strs.size() == 1) {
            result.push_back(strs);
            return result;
        }

        unordered_map<string, vector<string>> u_map;
        for(int i = 0; i < strs.size(); i++) {
            string key(strs[i]);
            sort(key.begin(), key.end());
            u_map[key].push_back(strs[i]);
        }

        for (auto &group : u_map)
        {
            result.push_back(group.second);
        }
        
        return result;
    } 
};

/**
 * @brief 
 * time: 0(nk)，k是字符串数组中的最长字符串长度，是一个常数，因此为0(n)
 * space: 0(n)
 */
class Solution_array {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> u_map;
        for(int i = 0; i < strs.size(); i++) {
            string key(26, 0);
            for (auto &ch : strs[i])
            {
                key[ch - 'a']++;
            }
            u_map[key].push_back(strs[i]);
        }

        for (auto &entry : u_map)
        {
            result.push_back(entry.second);
        }
        
        return result;
    }
};

#endif