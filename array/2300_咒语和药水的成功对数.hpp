#ifndef __SUCCESSFULPAIRS_HPP__
#define __SUCCESSFULPAIRS_HPP__

#include <vector>
using std::vector;
#include <algorithm>
using std::ranges::sort;
using std::ranges::upper_bound;

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size();      // 咒语的数量
        int m = potions.size();     // 药水的数量
        vector<int> result(spells.size(), 0);
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                // bug1: 这里存在问题，需要类型转换
                long long combination = static_cast<long long>(spells[i]) * potions[j];
                if(combination >= success) {
                    ++count;
                }
            }
            // bug2：之前已经留出空间了，只需要直接赋值就好
            result[i] = count;
        }

        return result;
    }
};

class Solution_erfen {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> potions, long long success) {
        sort(potions);
        for(int &x : spells) {
            long long target = (success - 1) / x;
            if(target < potions.back()) {
                x = potions.end() - upper_bound(potions, (int)target);
            } else {
                x = 0;
            }
        }
        
        return spells;
    }
};

#endif