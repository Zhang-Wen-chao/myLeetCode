// 700. Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/
#include <iostream>

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};

void inorderTraversal(TreeNode *root) {
    if (!root) return;
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode *root) {
    if (!root) return;
    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // Input the binary search tree
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    TreeNode *node = solution.searchBST(root, 2);

    // Output the subtree rooted with the found node
    std::cout << "The subtree rooted with the node with value " << 2 << " is: ";
    // inorderTraversal(node);
    preorderTraversal(node);
    std::cout << std::endl;

    return 0;
}

