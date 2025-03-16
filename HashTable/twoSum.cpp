#include <unordered_map>
#include <vector>

using namespace std;

// 每个数组只有一对数字可以匹配结果，而且不能重复使用同一个元素
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 为什么要使用unordered_map数据结构呢？首先使用unordered使用哈希表可以通过值进行最高效率的查找
        // 我们最重要返回的是indices，因此要保存键值对。key是数值，value是索引
        unordered_multimap<int, int> _numTable;
        for (int i = 0; i < nums.size(); ++i)
        {
            _numTable.insert(make_pair(nums[i], i));
        }
        for(auto bgit = _numTable.cbegin(), edit = _numTable.cend();
                     bgit != edit; ++bgit)
        {
            int value = target - bgit->first;
            auto aimit = _numTable.find(value);
            if(aimit != edit && aimit != bgit)
                return {bgit->second, aimit->second};
        }
        return {};
    }
};

class Soluntion_Answer {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 为什么在这个算法中就可以使用unordered_map，而不是unordered_multimap，因为从头到尾进行遍历的是vector
        // 而不是map，永远都不会出现自身与自身进行想加的情况，而且每组数组只有一个解决方案，因此相同的值使用一个就行
        // 一个下标索引进行表示就可以
        unordered_map<int, int> _table;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto aimit = _table.find(target - nums[i]);
            if(aimit != _table.end())
                return {aimit->second, i};
            _table.insert(make_pair(nums[i], i));
        }
        return {};
    }
};