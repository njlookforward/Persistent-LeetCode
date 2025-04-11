#ifndef INSERT_NODE_IN_BST_HPP
#define INSERT_NODE_IN_BST_HPP

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 找到正确的空节点，然后插入进入
class Solution_recursion {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if(root == nullptr) {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }
        if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};

#endif