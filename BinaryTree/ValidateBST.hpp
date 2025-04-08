#ifndef VALIDATE_BST_HPP
#define VALIDATE_BST_HPP

#include <vector>
using std::vector;

#include <algorithm>
using std::is_sorted;

#include <cstddef>
using std::size_t;

#include <climits>

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution_recursion {
public:
    void traversal(TreeNode *node, vector<int> &nums);
    bool isValidBST(TreeNode *root) {
        vector<int> nums;
        traversal(root, nums);
        // is_sorted(beg, end)不可以，is_sorted是判断数组是否以不降序顺序排列，包含相等的元素
        for (size_t i = 1; i < nums.size(); i++)
        {
            if(nums[i] <= nums[i-1])
                return false;
        }
        return true;    
    }
};

inline void Solution_recursion::traversal(TreeNode *node, vector<int> &nums)
{
    if(node->left) traversal(node->left, nums);
    nums.push_back(node->val);
    if(node->right) traversal(node->right, nums);
}

// 使用双指针法验证二叉搜索树，还是一步一步地去中序遍历就好
// 通过中序遍历，就像遍历数组一样
class Solution_recursion_doublePointer {
public:
    bool isValid(TreeNode *&pre, TreeNode *cur)
    {
        if(cur == nullptr) return true;
        bool left = isValid(pre, cur->left);
        if(pre && pre->val >= cur->val)
            return false;
        pre = cur;
        bool right = isValid(pre, cur->right);
        return left && right;
    }
    bool isValidBST(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        return isValid(pre, root);
    }
};

class Solution_recursion_max {
public:
    bool isValid(TreeNode *cur, long long &maxValue) {
        if(cur == nullptr) return true;
        bool left = isValid(cur->left, maxValue);
        if(cur->val > maxValue)
            maxValue = cur->val;
        else
            return false;
        bool right = isValid(cur->right, maxValue);
        return left && right;
    }
    bool isValidBST(TreeNode *root) {
        // 为什么要使用long long，因为这样肯定可以保证比节点中的任何值都小
        long long maxValue = LLONG_MIN;
        return isValid(root, maxValue);
    }
};

#endif