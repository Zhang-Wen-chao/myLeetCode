// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Input the first binary tree
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    // Input the second binary tree
    TreeNode *t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    Solution solution;
    TreeNode *mergedTree = solution.mergeTrees(t1, t2);

    // Output the merged binary tree
    std::cout << "The merged tree: ";
    printTree(mergedTree);

    return 0;
}

