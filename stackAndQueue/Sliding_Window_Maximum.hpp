#ifndef SLIDING_WINDOW_MAXIMUM_HPP
#define SLIDING_WINDOW_MAXIMUM_HPP

#include <vector>
using std::vector;

#include <deque>
using std::deque;

// 定义自己的单调队列，队列里的元素是单调递减的，只会
class DecreQue {
public:
    DecreQue() = default;
    ~DecreQue() = default;

    void push(int value);
    void pop(int value);
    int max() const;

private:
    deque<int> _que;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        DecreQue que;
        for (int  left = 0, right = 0; left + k <= nums.size(); ++left)
        {
            while (right < left + k)
            {
                que.push(nums[right++]);
            }
            res.push_back(que.max());
            que.pop(nums[left]);
        }
        return res;
    }
};

// inline void DecreQue::push(int value)
// {
//     while (!_que.empty() && _que.front() < value)
//     {
//         _que.pop_front();
//     }
//     // Bug: 如果仅判断队列头，一旦单调递减队列中出现5,1,3,4,2，那么下一次pop5，剩余队列中最大值应该是4
//     // 但返回的却是1，因此除判断队列头之外，还要判断队列尾，确保队列严格递减。
//     while (!_que.empty() && _que.back() < value)
//     {
//         _que.pop_back();
//     }
    
//     _que.push_back(value);
// }

// 答案的解法，我又想多了，直接从队列尾进行考虑就好了，想错了
inline void DecreQue::push(int value)
{
    while (!_que.empty() && _que.back() < value)
        _que.pop_back();
    _que.push_back(value);
}

inline void DecreQue::pop(int value)
{
    if(!_que.empty() && _que.front() == value)
        _que.pop_front();    
}

inline int DecreQue::max() const
{
    return _que.front();
}

#endif