// 0654. Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    int maxIndex = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[maxIndex]) maxIndex = i;
    }
    TreeNode *root = new TreeNode(nums[maxIndex]);
    vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
    root->left = constructMaximumBinaryTree(leftNums);
    vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
    root->right = constructMaximumBinaryTree(rightNums);
    return root;
}

void printTree(TreeNode *root) {
// print by level in an array and the nullptr is represented by #
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    int i = 0;
    while (i < nodes.size()) {
        if (nodes[i] == nullptr) {
            cout << "# ";
            i++;
            continue;
        }
        cout << nodes[i]->val << " ";
        nodes.push_back(nodes[i]->left);
        nodes.push_back(nodes[i]->right);
        i++;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode *root = constructMaximumBinaryTree(nums);
    printTree(root);
    return 0;
}