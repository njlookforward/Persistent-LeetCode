#include <iostream>
#include <string>
#include <vector>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        int num = 2;
        double &&dr = std::move(num);
    } 
};

void test1() {
    
}

int main(int argc, char *argv[]) {
    test1();

    return 0;
}