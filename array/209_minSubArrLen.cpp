#include <vector>
using namespace std;

// 使用滑动窗口法，i是窗口的起始位置，j是窗口的终止位置，i控制窗口的缩小，j控制窗口的扩大
// i和j的任务是独立的，分开的，他们唯一的纽带就是sum总和，这样问题就好思考了
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = __INT32_MAX__;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            sum += nums[j];
            while (sum >= target)
            {
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];   // 这是滑动窗口的精髓
            }
        }

        return result == __INT32_MAX__ ? 0 : result;
    }
};
// 时间复杂度为o(n)，最多两次遍历数列