#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode
{
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r): val(v), left(l), right(r) {}

    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution {
public:
    vector<int> preOrder(TreeNode *root) {
        vector<int> result;
        if(!root) return result;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }

        return result;
    }

    vector<int> Inorder(TreeNode *root) {
        vector<int> result;
        if(!root) return result;

        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(cur != nullptr || !st.empty()) {
            if(cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                result.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
        }

        return result;
    }

    vector<int> postOrder(TreeNode *root) {
        vector<int> result;
        if(!root) return result;

        stack<TreeNode*> st;
        st.push(root);
        TreeNode *cur = nullptr;
        while(!st.empty()) {
            cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }

        // 根 - 右 - 左  ---》 左 - 右 - 根
        reverse(result.begin(), result.end());
        return result;
    }
};