#ifndef FIND_DUPLICATE_MODE_BST_HPP
#define FIND_DUPLICATE_MODE_BST_HPP

#include <vector>
using std::vector;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 注意这是有重复节点的二叉搜索树，找到重复节点的众数
class Solution_recursion_doublePointer {
public:
    // Bug: 我的逻辑是有问题的，result的改变位置有问题
    // 不同的情况先改动occurs，然后在根据occurs与maxOccurs之间的关系进行result和maxOccurs的改动，不要混为一谈，要有顺序
    void inOrderFind(TreeNode *&pre, TreeNode *cur, int &occurs, int &maxOccurs, vector<int> &result)
    {
        if(cur == nullptr) return;
        inOrderFind(pre, cur->left, occurs, maxOccurs, result);
        // 要记住使用中序遍历，在中间作为单层递归逻辑，处理occurs,result和maxOccurs。别的地方是处理不了的，逻辑不要错
        if(pre == nullptr || pre->val != cur->val)
            occurs = 1;
        else {
            ++occurs;
        }
        if(occurs > maxOccurs) {
            maxOccurs = occurs;
            result.clear();
            result.push_back(cur->val);
        } else if(occurs == maxOccurs) {
            result.push_back(cur->val);
        }
        pre = cur;
        inOrderFind(pre, cur->right, occurs, maxOccurs, result);
    }
    vector<int> findMode(TreeNode *root)
    {
        int occurs = 0, maxOccurs = 0;
        vector<int> result;
        TreeNode *pre = nullptr;
        inOrderFind(pre, root, occurs, maxOccurs, result);
        return result;
    }
};

#endif