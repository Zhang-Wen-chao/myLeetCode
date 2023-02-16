// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/
#include <iostream>
#include <vector>
#include <map>

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
    std::vector<int> findMode(TreeNode* root) {
        std::map<int, int> count;
        int maxCount = 0;
        inorderTraversal(root, count, maxCount);
        
        std::vector<int> result;
        for (const auto &p : count) {
            if (p.second == maxCount) result.push_back(p.first);
        }
        
        return result;
    }
    
    void inorderTraversal(TreeNode *root, std::map<int, int> &count, int &maxCount) {
        if (!root) return;
        inorderTraversal(root->left, count, maxCount);
        count[root->val]++;
        maxCount = std::max(maxCount, count[root->val]);
        inorderTraversal(root->right, count, maxCount);
    }
};

int main() {
    // Input the binary search tree
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution solution;
    std::vector<int> result = solution.findMode(root);

    // Output the modes
    std::cout << "The modes are: ";
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

