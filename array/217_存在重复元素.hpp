#ifndef CONTAINDUPLICATE_HPP
#define CONTAINDUPLIACTE_HPP

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <unordered_map>
using std::unordered_map;

/**
 * @brief 先排序，再查看相邻数字是否重复
 * @note time complexity: O(nlogn) + 0(n)
 * space complexity: 0(logn)
 */
class Solution_sort {
public:
    bool containDupliacte(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1])
                return true;
        }

        return false;
    }
};

/**
 * @space complexity: 0(n)
 * time complexity: 0(n)
 */
class Solution_hash {
public:
    bool containDupliacte(vector<int> &nums) {
        unordered_map<int, int> hash_table;
        for(int i = 0; i < nums.size(); i++) {
            if(hash_table.count(nums[i])) 
                return true;
            else
                hash_table[nums[i]] = 1;
        }

        return false;
    }
};



#endif