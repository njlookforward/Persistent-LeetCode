#ifndef FINDDUPLICATE_HPP
#define FINDDUPLICATE_HPP

#include <vector>
using std::vector;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        // 因为容器大小为n+1, 容器内元素大小范围[1,n]
        // 因此必然存在重复元素，将每一个元素作为索引，索引从0开始
        // 必然会存在环
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

#endif