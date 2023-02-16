// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

private:
    void preorder(TreeNode* node, vector<int> &res) {
        if (node == NULL) return;
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = sol.preorderTraversal(root);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
