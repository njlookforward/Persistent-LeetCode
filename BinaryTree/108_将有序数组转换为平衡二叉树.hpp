#ifndef __SORTEDARRAY_BST_HPP_
#define __SORTEDARRAY_BST_HPP_

#include <iostream>
using std::cout, std::endl, std::cin;

#include <vector>
using std::vector;

struct TreeNode {
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode *build(vector<int> &nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode {nums[mid]};
        node->left = build(nums, left, mid - 1);
        node->right = build(nums, mid+1, right);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums, 0, nums.size()-1);
    }
};


#endif