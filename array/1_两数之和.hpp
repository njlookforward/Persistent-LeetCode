#ifndef TWOSUM_HPP
#define TWOSUM_HPP

#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    vector<int> twosum(vector<int> &nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {};
    }
};

/**
 * @brief 使用空间换时间的思想
 */
class Solution_hash {
public:
    vector<int> twosum(vector<int> &nums, int target) {
        unordered_map<int, int> u_map;
        for(int i = 0; i < nums.size(); i++) {
            u_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(u_map.find(target - nums[i]) != u_map.end() && u_map[target-nums[i]] != i)
                return {i, u_map[target-nums[i]]};
        }

        return {};
    }
};

class Solution_hash_v2 {
public:
    vector<int> twosum(vector<int> &nums, int target) {
        unordered_map<int, int> u_map;
        for(int i = 0; i < nums.size(); i++) {
            u_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(u_map.find(target - nums[i]) != u_map.end() && u_map[target-nums[i]] != i) {
                return {i, u_map[target-nums[i]]};
            }
        }

        return {};
    }
};

#endif