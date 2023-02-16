// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        string path;
        binaryTreePathsHelper(root, path, paths);
        return paths;
    }

private:
    void binaryTreePathsHelper(TreeNode* node, string& path, vector<string>& paths) {
        if (!node->left && !node->right) {
            path += to_string(node->val);
            paths.push_back(path);
            return;
        }
        path += to_string(node->val) + "->";
        if (node->left) binaryTreePathsHelper(node->left, path, paths);
        if (node->right) binaryTreePathsHelper(node->right, path, paths);
        path.resize(path.size() - to_string(node->val).size() - 2);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);

    cout << "[";
    for (int i = 0; i < paths.size(); i++) {
        cout << "\"" << paths[i] << "\"";
        if (i != paths.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
