#ifndef _PRODUCTEXCEPTSELF_HPP_
#define _PRODUCTEXCEPTSELF_HPP_

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1);
        int length = nums.size();
        int prefixProduct = 1, postfixProduct = 1;
        for(int i = 0; i < length-1; i++) {
            prefixProduct *= nums[i];
            prefix[i+1] = prefixProduct;
        }
        for(int j = length - 1; j > 0; j--) {
            postfixProduct *= nums[j];
            postfix[j - 1] = postfixProduct;
        }
        vector<int> result(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            result[i] = prefix[i] * postfix[i];
        }

        return result;
    }
};

// 可以使用优化后的代码，就是先计算每一个节点的前缀积，然后再计算每一个节点的后缀积
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution_v2 {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        auto length = nums.size();
        vector<int> res(nums.size(), 1);

        // 先计算每一个节点的前缀积，必须从1开始乘
        int prefix = 1;
        for(int i = 1; i < length; i++) {
            prefix *= nums[i-1];
            res[i] = prefix;
        }
        // 再计算每一个节点的后缀积，也必须从1开始乘
        int postfix = 1;
        for(int j = length - 2; j >= 0; j--) {
            postfix *= nums[j+1];
            // 这里不能简单地赋值，而是需要乘上后缀积
            // res[j] = postfix;
            res[j] *= postfix;
        }

        return res;
    }
};

#endif