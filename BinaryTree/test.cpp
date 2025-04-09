// #include "InorderTraversal.hpp"
// #include "IterationTraversal.hpp"
#include "MinAbsoluteDifference.hpp"
#include <iostream>
using std::cout; using std::endl;

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

void test_getMinDifference()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(7);

    auto min = Solution_recursion_doublePointer().getMinimumDifference(root);
    cout << "min = " << min << endl;

    delete root->right;
    delete root->left;
    delete root;
}

int main()
{
    // test_inorderTraversal();
    test_getMinDifference();

    return 0;
}