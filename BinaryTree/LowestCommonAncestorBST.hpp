#ifndef LOWEST_COMMON_ANCESTOR_BST_HPP
#define LOWEST_COMMON_ANCESTOR_BST_HPP

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if((root->val >= p->val && root->val <= q->val) ||
           (root->val >= q->val && root->val <= p->val))
           return root;
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return lowestCommonAncestor(root->left, p, q);
    }
};

class Solution_general {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == p || root == q || !root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right)
            return root;
        else if(left && !right)
            return left;
        else if(!left && right)
            return right;
        else 
            return nullptr;
    }
};

#endif