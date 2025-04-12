#ifndef CONVERTBST_GREATER_TREE
#define CONVERTBST_GREATER_TREE

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

// 从最后进行累加，因此递归顺序为右-中-左
// 
class Solution_recursion {
public:
    void traversal(TreeNode *node, int &sum) {
        if(node == nullptr) return;
        traversal(node->right, sum);
        // Bug:马虎问题，将node写成了root
        node->val += sum;
        sum = node->val;
        traversal(node->left, sum);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        traversal(root, sum);
        // Bug: 编译错误，多次这种错误了，忘记写返回值
        return root;
    }
};

#endif  // CONVERTBST_GREATER_TREE