// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode *left = invertTree(root->left), *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    Solution solution;
    TreeNode *result = solution.invertTree(root);
    cout << result->val << endl;
    cout << result->left->val << " " << result->right->val << endl;
    cout << result->left->left->val << " " << result->left->right->val << " " << result->right->left->val << " " << result->right->right->val << endl;
    
    return 0;
}
