#ifndef BINARY_TREE_CAMERAS_HPP
#define BINARY_TREE_CAMERAS_HPP

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}
};

/**
 * @brief 这是一道贪心算法与二叉树的结合，一个节点放上摄像头就可以monitor自身、父节点、孩子节点，需要找到最少的
 * 放置摄像头的数量，能够覆盖二叉树中的所有节点
 * @details 
 * 1) 树中的每个节点的状态一共分为三种: a) 无覆盖0  b) 有摄像头1    c) 有覆盖2
 * 2）思考如何放置能够使用最少数量的摄像头来覆盖全部节点，应该是从多的一方，即叶子结点处开始遍历，在叶子结点的
 * 父节点开始放置摄像头，然后跳过两层再放置摄像头，这样就能保证数量最少，因此采用后序遍历，一共有三种单纯的状态转移
 * 3) a)左右孩子都被覆盖，父节点应该是无覆盖0；
 * b) 左右节点只有有一个孩子无覆盖，父节点应该是有摄像头1
 * c) 左右孩子节点至少有一个摄像头，那么父节点一定是有覆盖2
 * 4) 最后有一种特殊情况需要单独考虑，就是左右孩子都有覆盖，那么此时的父节点应该是无覆盖0，但是该父节点也是根节点
 * 他没有父节点防止摄像头，需要自身放置摄像头
 * 5) 还有需要考虑空节点应该是什么状态，为了保证叶子结点的父节点有摄像头，空节点应该是有覆盖
*/

class Solution {
public:
    int traversal(TreeNode *node, int &result) {
        if(node == nullptr) return 2;
        int left = traversal(node->left, result);
        int right = traversal(node->right, result);
        if(left == 2 && right == 2) return 0;
        if(left == 0 || right == 0) {
            result++;
            return 1;
        }
        if(left == 1 || right == 1) return 2;
        return -1;  // 其实没有用，前面所有情况都已经考虑到了，这里是用来满足语法要求的
    }

    int minCameraCover(TreeNode *root) {
        int result = 0;
        if(traversal(root, result) == 0) {
            ++result;
        }
        return result;
    }
};

#endif