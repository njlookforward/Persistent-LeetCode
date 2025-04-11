#ifndef DELETE_NODE_IN_BST_HPP
#define DELETE_NODE_IN_BST_HPP

#include <utility>
using std::swap;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 使用的是前序遍历，删除BST中的节点是比较麻烦的，因为可能出现二叉树结构的重塑，需考虑多种情况
// 1. 没有找目标值，直接返回
// 2. 目标值为叶子结点，左为空右为空
// 3. 目标值节点左不为空，右为空
// 4. 目标值节点左为空，右不为空
// 5. 目标值节点左不为空，右不为空
class Solution_recursion {
public:
    TreeNode *deleteNode(TreeNode *root, int key) 
    {
        if(root == nullptr) return nullptr;
        if(root->val == key) {
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                TreeNode *newRoot = root->left;
                delete root;
                return newRoot;
            } else if (root->left == nullptr && root->right != nullptr) {
                TreeNode *newRoot = root->right;
                delete root;
                return newRoot;
            } else {
                TreeNode *newRoot = root->right;
                TreeNode *cur = newRoot;
                while (cur->left != nullptr)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                delete root;
                return newRoot;
            }
        }
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};

// 无论对于普通二叉树，还是二叉搜索树的通用写法
class Solution_general {
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if(root == nullptr) return root;
        if(root->val == key) {
            if(!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (root->left && !root->right) {
                TreeNode *newRoot = root->left;
                delete root;
                return newRoot;
            } else if (!root->left && root->right) {
                TreeNode *newRoot = root->right;
                delete root;
                return newRoot;
            } else {
                TreeNode *cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                swap(root->val, cur->val);
                // 将左右不为空转换为以上三种情况之一
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};

#endif