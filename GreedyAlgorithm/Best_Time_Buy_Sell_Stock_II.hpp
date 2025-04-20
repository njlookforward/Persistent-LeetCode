#ifndef BEST_TIME_BUT_SELL_STOCK_II_HPP
#define BEST_TIME_BUY_SELL_STOCK_II_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

#include <cstddef>
using std::size_t;

// key:把取区间利润分为每日利润，把所有的正利润都加在一起，就可以得到最大的利润
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        for(size_t i = 1; i < prices.size(); ++i) {
            result += max(prices[i] - prices[i-1], 0);
        }

        return result;
    }
};

#endif