#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;
using std::unordered_map;

class Solution
{
    // 方法一：仍然是使用哈希表
    // 时间复杂度： O(n)
    // 空间复杂度： O(n) 使用了哈希表
    int majorityElement_v1(vector<int> &nums)
    {
        unordered_map<int, int> u_map;
        int maxOccurs = 0;  // 存储当前的最大出现次数
        int res = 0;        // 对应的当前最大出现次数的数字
        // 遍历整个数组，将数字与出现次数存储在哈希表中
        // 如果更新后的哈希表的出现次数大于当前最大次数，则更新两个数据
        // 只需要遍历一次数组，就可以得到最终的结果
        for(auto & elem : nums)
        {
            u_map[elem]++;
            if(u_map[elem] > maxOccurs)
            {
                maxOccurs = u_map[elem];
                res = elem;
            }
        }
        return res;
    }

    // 方法二：可以先排序，然后中间的元素就是多数元素，因此次数>n/2
    // 时间： O(nlogn)
    // 空间： O(1)
    int majorityElement_v2(vector<int> &nums)
    {
        // 先排序nums
        std::sort(nums.begin(), nums.end());
        // 然后返回中间元素
        std::size_t size = nums.size();
        return nums[size / 2];
    }

    // 方法三：使用摩尔投票的方法，局限性是必须只有一个最大的元素，如果存在两个次数最多的元素，就会得到错误的结果
    // time: O(n)
    // space: O(1)
    int majorityElement_v3(vector<int> &nums)
    {
        // 使用两个变量作为数据结构
        int count = 0;
        int res = 0;
        for(int ele : nums)
        {
            if(count == 0)
            {
                count = 1;
                res = ele;
            } else if(ele != res)
            {
                count--;
            } else {
                count++;
            }
        }
        return res;
    }
};
void test1() {
    
}

int main(int argc, char *argv[]) {
    test1();

    return 0;
}