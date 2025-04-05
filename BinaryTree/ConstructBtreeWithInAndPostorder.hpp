#ifndef CONSTRUCT_BTREE_WITH_INANDPOSTORDER_HPP
#define CONSTRUCT_BTREE_WITH_INANDPOSTORDER_HPP

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

// 首先，如何构造一棵树呢，总的过程就是一个根节点一个根节点的创造
// 该题的核心就是正确地切割中序遍历和后序遍历，算法逻辑如下
// 1. 判断后序遍历是否为空，若为空则返回nullptr
// 2. 找到后序遍历的最后一个节点值，这是根节点，创造根节点
// 3. 在中序遍历中找到根节点的位置
// 4. 切割中序
// 5. 切割后序
// 6. 在左子树和右子树中进行递归
class Solution_recursion {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // if(postorder.empty()) return nullptr;
        auto rootVal = postorder.back();
        TreeNode *root = new TreeNode(rootVal);
        if(postorder.size() > 1) {
            // 这是整个切割的操作
            size_t rootIndex;
            for (size_t i = 0; i < inorder.size(); i++)
            {
                if(inorder[i] == rootVal) {
                    rootIndex = i;
                    break;
                }
            }
            vector<int> leftInorder(inorder.cbegin(), inorder.cbegin() + rootIndex),
                        rightInorder(inorder.cbegin() + rootIndex + 1, inorder.cend());
            postorder.pop_back();
            vector<int> leftPostorder(postorder.cbegin(), postorder.cbegin() + leftInorder.size()),
                        rightPostorder(postorder.cbegin() + leftInorder.size(), postorder.cend());

            // Bug:需要进行判断遍历数组是否为空，否则会出问题
            if(!leftInorder.empty())
                root->left = buildTree(leftInorder, leftPostorder);
            if(!rightInorder.empty())
                root->right = buildTree(rightInorder, rightPostorder);
        }
        return root;
    }
};


#endif