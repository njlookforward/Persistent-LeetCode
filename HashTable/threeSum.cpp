#include <vector>
#include <algorithm>
using namespace std;

// 注意去重的意思是不能有重复的三元组，而不是三元组内不能重复
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        // 寻找的是nums[i] + nums[j] + nums[k] = 0 && i != j && i != k && j != k
        for(int i = 0; i < nums.size(); ++i)
        {
            // 使用双指针法，要固定一个，去移动另外两个，这种思想一定要把握
            if(nums[i] > 0) return results; // 不可能有三元组等于0
            if(i > 0 && nums[i] == nums[i-1]) continue; // 对a去重
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)    // 因为索引必须都不相同，所以这个条件
            {
                // 先收货结果，再进行去重
                if(nums[i] + nums[left] + nums[right] > 0)
                    --right;
                else if(nums[i] + nums[left] + nums[right] < 0)
                    ++left;
                else {
                    results.push_back({nums[i], nums[left], nums[right]});
                    ++left, --right;
                    while(right > left && nums[left] == nums[left - 1]) ++left;     // 对left进行去重
                    while(right > left && nums[right] == nums[right + 1]) --right;  // 对right进行去重
                }
            }
        }
        return results;
    }
};
