#ifndef MAXPROFIT_HPP
#define MAXPROFIT_HPP

#include <vector>
using std::vector;
#include <climits>

// sell - buf = profix
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 1) return 0;

        int maxProfit = INT_MIN;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            int curProfit = prices[i] - minPrice;
            maxProfit = maxProfit < curProfit ? curProfit
                                              : maxProfit;
            minPrice = minPrice <= prices[i] ? minPrice
                                             : prices[i];
        }

        if(maxProfit <= 0) return 0;
        else
            return maxProfit;
    }
};

class Solution_v2 {
public:
    int maxProfit(vector<int> &prices) {
        int pricesLen = prices.size();
        int buy_price = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < pricesLen; i++) {
            if(prices[i] < buy_price) {
                // 逢低买入
                buy_price = prices[i];
            } else if(prices[i] - buy_price > maxProfit) {
                maxProfit = prices[i] - buy_price;
            } 
        }

        return maxProfit;
    }
};

#endif