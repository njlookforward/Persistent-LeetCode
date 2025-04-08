#ifndef MERGETREES_HPP
#define MERGETREES_HPP

#include <queue>
using std::queue;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 还是核心要点：二叉树的整体结构是：根节点+左子树+右子树，左子树和右子树的结构同样如此
class Solution_recursion_new {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 要谨记两节点合并才是新的一个节点
        if(root1 == nullptr) {
            if(root2 == nullptr) return nullptr;
            else {
                TreeNode *root = new TreeNode(root2->val);
                root->left = mergeTrees(nullptr, root2->left);
                root->right = mergeTrees(nullptr, root2->right);
                return root;
            }
        }
        else if (root2 == nullptr) {
            if(root1 == nullptr) return nullptr;
            else {
                TreeNode *root = new TreeNode(root1->val);
                root->left = mergeTrees(root1->left, nullptr);
                root->right = mergeTrees(root1->right, nullptr);
                return root;
            }
        }
        // 这是先序遍历，中左右
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

class Solution_recursion_merge {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) 
    {
        if(root1 == nullptr) return root2;  // 把root2整棵子树都作为新的子树
        if(root2 == nullptr) return root1;
        root1->val += root2->val;
        // 其实root1->left and root1->right始终没有变，除非该节点为空，而root2对应位置由节点，然后移过来
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

class Solution_iteration_level {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty())
        {
            // 每次队列弹出相同位置的两个节点
            TreeNode *left = que.front(); que.pop();
            TreeNode *right = que.front(); que.pop();
            left->val += right->val;
            // 每次队列放入相同位置的两个节点
            if(left->left != nullptr && right->left != nullptr) {
                que.push(left->left);
                que.push(right->left);
            }
            if(left->right != nullptr && right->right != nullptr) {
                que.push(left->right);
                que.push(right->right);
            }
            if(left->left == nullptr && right->left != nullptr) {
                left->left = right->left;
            }
            if(left->right == nullptr && right->right != nullptr) {
                left->right = right->right;
            }
        }
        return root1;
    }
};


#endif