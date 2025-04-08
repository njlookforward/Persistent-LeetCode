#ifndef CONSTRUCT_MAXIMUM_BTREE_HPP
#define CONSTRUCT_MAXIMUM_BTREE_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::max_element;

#include <cstddef>
using std::size_t;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 这道给出了根据一个数组构造最大二叉树的方法（最高的二叉树）
// 构造一棵二叉树的递归方法就是使用前序遍历
class Solution_recursion {
public:
    TreeNode *construct(vector<int> &nums, size_t left, size_t right);
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return construct(nums, 0, nums.size());
    }
};

inline TreeNode* Solution_recursion::construct(vector<int> &nums, size_t left, size_t right)
{
    // 终止条件：到达叶子结点就返回
    if(right - left == 1) {
        return new TreeNode(nums[left]);
    }
    auto maxiter = max_element(nums.cbegin() + left, nums.cbegin() + right);
    TreeNode *root = new TreeNode(*maxiter);
    // 因为终止条件是到达叶子结点，因此必须保证子数组区间长度大于等于1
    if(maxiter > nums.cbegin() + left) {
        root->left = construct(nums, left, maxiter - nums.cbegin());
    }
    if(maxiter < nums.cbegin() + right - 1) {
        root->right = construct(nums, maxiter - nums.cbegin() + 1, right);
    }
    return root;
}

#endif