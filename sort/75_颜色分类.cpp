#include <iostream>
#include <string>
#include <vector>
#include <array>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;
using std::array;

class Solution 
{
public:
    // 方法一：找出特殊，只有三种颜色，也就是数组中只有三个数字，按照从小到大的顺序进行排列
    // 可以通过一个哈希表，遍历元素，得到每一个数字有多少个，然后再赋值回去就好
    // time: O(n)
    // space: O(1)
    void sortColors(vector<int> &nums)
    {
        array<int, 3> hashTable {0} ;   // 通过列表初始化进行值初始化
        for(int num : nums)
        {
            hashTable[num]++;
        }
        size_t idx = 0;
        for(size_t i = 0; i < hashTable.size(); i++)
        {
            // 根据哈希表存储的次数，作为赋值的次数
            for(size_t j = 0; j < hashTable[i]; j++)
            {
                nums[idx++] = i;
            }
        }
    }

    // 方法二：直接自己进行快速排序，或者归并排序，但是这样时间复杂度和空间复杂度都是O(nlogn)
    // 方法三：使用双指针法，[L,R]是没有确定元素最终值的范围，对整个数组进行分区间划分
    // [0, L)是0； [L,R]是1，(R, n)是2，i作为遍历整个数组的索引，和快速排序一种实现方法非常类似
    // 把某一个元素该放入的位置直接放过去
    void sortColors_v2(vector<int> &nums)
    {
        int idx = 0;
        // L是0的位置，R是2的位置，中间是1的位置
        for(int left = 0, right = nums.size() - 1; idx <= right;)
        {
            // [left, right]之间是未被处理的元素，或者是处理完后，都是1的元素范围
            // 需要分情况讨论，nums[idx]==0与left交换元素
            if(nums[idx] == 0)
            {
                // idx与left都是从0出发，因此idx与left只有两种位置关系
                // 一是：left与idx处于同一位置，因此交换后两者都要++
                // 二是：left与idx处于不同位置，idx超过left，idx处理过的元素都是按照000111的顺序排列的
                // 因此在这种情况下，交换后nums[idx]肯定等于1，因此也要和left一样同时向后移动
                std::swap(nums[left], nums[idx]);
                left++;
                idx++;
            } else if(nums[idx] == 2)
            {
                // nums[idx] == 2需要与right交换元素
                // 不能轻易移动idx，因为交换过来的元素可能为2，可能为0，因此需要在下一次循环中进行判断
                std::swap(nums[idx], nums[right]);
                right--;
            } else 
            {
                // nums[idx] == 1的时候，满足[left,right]的区间要求，直接continue就好
                idx++;
            }
        }
    }
};

void test1() {
    // vector<int> nums {1,2,0};
    // vector<int> nums {1,0};
    vector<int> nums {2,0,2,1,1,0};
    // vector<int> nums {1,2,0};
    // vector<int> nums {2,1,2};
    Solution().sortColors_v2(nums);
    for(auto elem : nums)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    test1();

    return 0;
}