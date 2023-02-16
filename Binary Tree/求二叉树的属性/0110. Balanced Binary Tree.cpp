// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
#include <iostream>

using namespace std;

// Definition for a binary tree node
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
    int getHeight(TreeNode *root) {
        if (!root) return -1;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        if (abs(left_height - right_height) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    cout << (sol.isBalanced(root) ? "True" : "False") << endl;
    return 0;
}
