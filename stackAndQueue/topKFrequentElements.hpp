#ifndef TOP_K_FREQUENT_ELEMENTS_HPP
#define TOP_K_FREQUENT_ELEMENTS_HPP

#include <vector>
using std::vector;

#include <queue>
using std::priority_queue;

#include <unordered_map>
using std::unordered_map;

#include <utility>
using std::pair;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 记录输入序列中个元素出现的次数的键值对
        // Bug；尽量使用unordered_map, 而不是map，运行时间从7nm感到3nm
        unordered_map<int, int> occurs;
        for (auto num : nums)
        {
            occurs[num]++;
        }
        
        // 对这个map出现次数需要进行排序，留下次数最高的k个键值对，使用小顶堆
        auto Comp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        };  // Bug: 不要忘记;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       decltype(Comp)> topk(Comp);  // 不要忘记把比较函数传给构造函数
        for (auto &entry : occurs)
        {
            // topk.push(entry);
            // if(topk.size() > k)
            //     topk.pop();
            // 以上部分可以进行优化，只弹出真正次数更少的元素, 这样优化后，从3nm直接来到0nm，真是厉害啊
            // 只替换为真正次数更多的元素
            if(topk.size() == k) {
                if(topk.top().second < entry.second) {
                    topk.pop();
                    topk.push(entry);
                }
            } else {
                topk.push(entry);
            }
        }
        
        // 根据次数对键值对进行排序后，需要将元素放入集合中进行返回
        vector<int> res(k);
        for(int i = k - 1; i >= 0; --i)
        {
            res[i] = topk.top().first;
            topk.pop();
        }
        
        return res;
    }
};

#endif