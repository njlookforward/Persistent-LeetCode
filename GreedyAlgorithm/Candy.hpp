#ifndef CANDY_HPP
#define CANDY_HPP

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

#include <algorithm>
using std::max;

/**
 * @details 遇到这种需要考虑两边的情况，要先考虑一边，再考虑另一边，不能一起想，否则会顾此失彼
 * 先考虑右孩子比左孩子大的情况，再考虑左孩子比右孩子大的情况，取最大值
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candies(ratings.size(), 1);
        // 先考虑右孩子是否比左孩子大
        for(int i = 1; i < ratings.size(); ++i) {
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        // 再考虑左孩子是否比右孩子大
        for(int i = ratings.size() - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i+1] + 1, candies[i]);
            }
        }
        return accumulate(candies.cbegin(), candies.cend(), 0);
    }
};


#endif