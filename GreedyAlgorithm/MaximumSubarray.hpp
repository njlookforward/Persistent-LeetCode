#ifndef MAXIMUM_SUBARRAY_HPP
#define MAXIMUM_SUBARRAY_HPP

#include <vector>
using std::vector;

#include <climits>

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            if(count > result) result = count;
            if(count < 0) count = 0;
        }

        return result;
    }
};

#endif