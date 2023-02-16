// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/
#include <iostream>
#include <cmath>
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left_depth = 0, right_depth = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            ++left_depth;
            left = left->left;
        }
        while (right) {
            ++right_depth;
            right = right->right;
        }
        if (left_depth == right_depth) return pow(2, left_depth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution sol;
    cout << sol.countNodes(root) << endl;
    return 0;
}
