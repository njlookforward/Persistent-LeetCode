#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 只要会了三数之和，那么四数之和、五数之和都是一样的道理，三数之和是O(n^2), 四数之和就是O(n^3)
        // 通过使用双指针法可以将算法复杂度降一个数量级
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i)
        {
            // 固定a，在这一个外循环中找到所有以a为一个元素的四元组
            // Bug：这里存在问题，如果是0相加就没事，就不应该有这个判断，谁规定的相加之后的结果不能比数组中的数小呢
            // if(nums[i] > target)
                // return results;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;   // a进行去重
            for(int j = i + 1; j < nums.size(); ++j)
            {
                // 固定b,在这一个内循环中找到所有以a,b为前两个元素的四元组
                if(j > (i + 1) && nums[j] == nums[j - 1])
                    continue;   // b进行去重
                // Bug: 竟然索引写错了，可恶啊，心要净
                for(int left = j + 1, right = nums.size() - 1;
                    right > left;)
                {
                    // Bug: 有符号整数可能出现上溢
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target)
                        --right;
                    else if(sum < target)
                        ++left;
                    else {
                        results.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while(right > left && nums[left] == nums[left - 1]) ++left;
                        while(right > left && nums[right] == nums[right + 1]) --right;
                    }
                }
            }
        }
        return results;
    }
};

int main()
{
    // vector<int> nums{1, 0, -1, 0, -2, 2};
    // vector<int> nums{2,2,2,2,2};
    vector<int> nums{1,-2,-5,-4,-3,3,3,5};
    // int target = 0;
    int target = -11;
    auto results = Solution().fourSum(nums, target);
    for(const auto &entry : results)
    {
        for (auto &i : entry)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}