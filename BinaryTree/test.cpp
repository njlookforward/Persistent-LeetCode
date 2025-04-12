// #include "InorderTraversal.hpp"
// #include "IterationTraversal.hpp"
// #include "MinAbsoluteDifference.hpp"
// #include "findDuplicateModeinBST.hpp"
#include "TrimBST.hpp"
#include <iostream>
using std::cout; using std::endl;

#include <stack>
using std::stack;

#include <vector>
using std::vector;

// void test_inorderTraversal()
// {
//     TreeNode *root = new TreeNode(1);
//     root->right = new TreeNode(2);
//     root->right->left = new TreeNode(3);
    
//     auto res = Solution_iteration_recap1().inorder(root);
//     for (auto i : res)
//     {
//         cout << i << " ";
//     }
//     cout << endl;

//     delete root->right->left;
//     delete root->right;
//     delete root;
// }

// void test_getMinDifference()
// {
//     TreeNode *root = new TreeNode(5);
//     root->left = new TreeNode(4);
//     root->right = new TreeNode(7);

//     auto min = Solution_recursion_doublePointer().getMinimumDifference(root);
//     cout << "min = " << min << endl;

//     delete root->right;
//     delete root->left;
//     delete root;
// }

// void test_findDuplicate()
// {
//     TreeNode *root = new TreeNode(1);
//     root->right = new TreeNode(2);

//     auto result = Solution_recursion_doublePointer().findMode(root);
//     for (auto &i : result)
//     {
//         cout << i << " ";
//     }
//     cout << endl;

//     delete root->right;
//     delete root;
// }

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> result;
    if(!root) return result;
    
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty())
    {
        // Bug: 逻辑出问题了
        // 脑袋出问题了，!cur代表cur为空啊
        if(cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
    }
    return result;
}

void test_trimBST()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);

    TreeNode *newRoot = Solution_recursion().trimBST(root, 2, 4);
    auto result = inorderTraversal(newRoot);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    // test_inorderTraversal();
    // test_getMinDifference();
    // test_findDuplicate();
    test_trimBST();

    return 0;
}