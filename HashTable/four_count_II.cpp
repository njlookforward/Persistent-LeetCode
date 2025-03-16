#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, 
                     vector<int> &nums3, vector<int> &nums4)
    {
        // 为什么要使用unordered_map呢？因为使用哈希表查找效率最高，那为什么使用map呢，因为
        // 需要使用键值对结构保存<add_result, countTimes>;
        unordered_map<int, int> _mapSum;
        for (auto &lhs : nums1)
        {
            for (auto &rhs : nums2)
            {
                ++_mapSum[lhs + rhs];
            }
        }
        int zeroCnt = 0;
        for (auto &lhs_3 : nums3)
        {
            for (auto &rhs_4 : nums4)
            {
                auto findit = _mapSum.find(0 - lhs_3 - rhs_4);
                if(findit != _mapSum.end())
                    zeroCnt += findit->second;
            }
        }
        return zeroCnt;
    }
};