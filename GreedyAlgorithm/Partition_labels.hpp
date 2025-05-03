#ifndef PARTITION_LABELS_HPP
#define PARTITION_LABELS_HPP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

#include <cstddef>
using std::size_t;

/**
 * @brief 划分字母区间，要求相同字母只能出现在一个区间中
 * @details 这里要使用“哈希”的思想，首先遍历字符串，通过一个哈希数组记录每一个字母出现的最远位置，然后再次从头遍历
 * 字符串，通过left和right记录每一个分区间的左右边界，只要向前遍历的过程中当前字母的最远出现位置大于right，就更新right
 * 当当前位置等于right时说明已经得到了一个分区间，该区间中的所有字母只会出现在这个区间中，然后更新result和left
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        size_t hash[27] = {0};
        for(size_t i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a'] = i;
        }
        size_t left = 0, right = 0;
        vector<int> result;
        for(size_t i = 0; i < s.size(); ++i) {
            right = max(right, hash[s[i] - 'a']);
            if(i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return result;
    }
};

#endif