#ifndef CONVERT_SORTEDARRAY_BST
#define CONVERT_SORTEDARRAY_BST

#include <vector>
using std::vector;

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

// 构造一颗二叉树就要使用先序遍历，创建一颗颗小子树，最后构成整棵BST
class Solution_recursion {
public:
    TreeNode *build(vector<int> &nums, size_t left, size_t right)
    {
        if(left >= right) return nullptr;
        // Bug:
        size_t mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid);
        root->right = build(nums, mid+1, right);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size());
    }
};

#endif