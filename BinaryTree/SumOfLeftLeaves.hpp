#ifndef SUM_OF_LEFT_LEAVES_HPP
#define SUM_OF_LEFT_LEAVES_HPP

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
    void traversal(TreeNode *cur, int &sum, bool left);
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        if(!root) return sum;
        traversal(root, sum, false);
        return sum;
    }
};

inline void Solution_recursion::traversal(TreeNode *cur, int &sum, bool left)
{
    // 遍历到叶子结点就终止，因此遍历的节点必须有效
    if(cur->left == nullptr && cur->right == nullptr)
    {
        if(left)
            sum += cur->val;
        return;
    }
    if(cur->left)  traversal(cur->left, sum, true);
    if(cur->right) traversal(cur->right, sum, false);
}

class Solution_recursion_carl {
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(root == nullptr) return 0;
        if(!root->left && !root->right) return 0;

        int leftSum = sumOfLeftLeaves(root->left);
        // Key: 找到左叶子结点的父节点，然后更新值
        if(root->left && !root->left->left && !root->left->right)
            leftSum = root->left->val;
        int rightSum = sumOfLeftLeaves(root->right);
        return leftSum + rightSum;
    }
};

#endif  