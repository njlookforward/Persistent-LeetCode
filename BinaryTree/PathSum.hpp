#ifndef PATHSUM_HPP
#define PATHSUM_HPP

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 先序遍历
class Solution_recursion {
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if(root == nullptr) return false;
        targetSum -= root->val;
        if(!root->left && !root->right) {
            // 到达一条路径的叶子结点，需要进行判断
            return targetSum == 0;
        }
        if(root->left) {
            if(hasPathSum(root->left, targetSum))
                return true;
        }
        if(root->right) {
            if(hasPathSum(root->right, targetSum))
                return true;
        }
        return false;
    }

    bool hasPathSum_v2(TreeNode *root, int targetSum)
    {
        if(root == nullptr) return false;
        if(!root->left && !root->right) {
            return root->val == targetSum;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};


#endif