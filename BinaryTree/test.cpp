#include "InorderTraversal.hpp"
#include <iostream>
using std::cout; using std::endl;

void test_inorderTraversal()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    auto res = Solution_iterator().inorderTraversal(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    delete root->right->left;
    delete root->right;
    delete root;
}

int main()
{
    test_inorderTraversal();

    return 0;
}