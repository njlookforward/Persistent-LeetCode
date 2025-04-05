#ifndef CONSTRUCT_BTREE_WITH_PREANDINORDER_HPP
#define CONSTRUCT_BTREE_WITH_PREANDINORDER_HPP

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

class Solution_recursion {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int rootVal = preorder.front();
        TreeNode *root = new TreeNode(rootVal);
        if(preorder.size() > 1) {
            size_t delimIndex;
            for(delimIndex = 0; delimIndex < inorder.size(); ++delimIndex)
            {
                if(inorder[delimIndex] == rootVal) break;
            }

            vector<int> leftInorder(inorder.cbegin(), inorder.cbegin() + delimIndex),
                        rightInorder(inorder.cbegin() + delimIndex + 1, inorder.cend());
            vector<int> leftPreorder(preorder.cbegin() + 1, preorder.cbegin() + 1 + leftInorder.size()),
                        rightPreorder(preorder.cbegin() + 1 + leftInorder.size(), preorder.cend());
            
            if(!leftInorder.empty())
                root->left = buildTree(leftPreorder, leftInorder);
            if(!rightInorder.empty())
                root->right = buildTree(rightPreorder, rightInorder);
        }
        return root;
    }
};

#endif