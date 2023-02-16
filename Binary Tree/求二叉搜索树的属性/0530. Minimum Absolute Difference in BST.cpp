// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
#include <iostream>
#include <climits>

// Definition for a binary tree node.
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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = INT_MIN;
        inorderTraversal(root, minDiff, prev);
        return minDiff;
    }
    
    void inorderTraversal(TreeNode *root, int &minDiff, int &prev) {
        if (!root) return;
        inorderTraversal(root->left, minDiff, prev);
        if (prev != INT_MIN) minDiff = std::min(minDiff, root->val - prev);
        prev = root->val;
        inorderTraversal(root->right, minDiff, prev);
    }
};

int main() {
    // Input the binary search tree
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    Solution solution;
    int result = solution.getMinimumDifference(root);

    // Output the minimum absolute difference
    std::cout << "The minimum absolute difference is: " << result << std::endl;

    return 0;
}
