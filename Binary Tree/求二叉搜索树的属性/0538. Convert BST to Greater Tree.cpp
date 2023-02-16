// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& nums, int i) {
    if (i >= nums.size() || nums[i] == INT_MIN) return NULL;
    TreeNode* root = new TreeNode(nums[i]);
    root->left = buildTree(nums, 2 * i + 1);
    root->right = buildTree(nums, 2 * i + 2);
    return root;
}

vector<int> outputTree(TreeNode* root) {
    vector<int> result;
    vector<TreeNode*> currentLevel, nextLevel;
    currentLevel.push_back(root);
    while (!currentLevel.empty()) {
        for (auto node : currentLevel) {
            if (node == NULL) {
                result.push_back(INT_MIN);
                nextLevel.push_back(NULL);
                nextLevel.push_back(NULL);
            } else {
                result.push_back(node->val);
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            }
        }
        if (nextLevel.back() == NULL) {
            while (!nextLevel.empty() && nextLevel.back() == NULL) nextLevel.pop_back();
        }
        currentLevel = nextLevel;
        nextLevel.clear();
    }
    return result;
}
void printTree(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        int nullCount = 0;
        for (int i = 0; i < n; i++) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                result.push_back(INT_MIN);
                nullCount++;
                q.push(nullptr);
                q.push(nullptr);
            } else {
                result.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (nullCount == n) break;
    }
    while (result.back() == INT_MIN) result.pop_back();
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == INT_MIN) cout << "# ";
        else cout << result[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != NULL) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

int main() {
    vector<int> nums = {4,1,6,0,2,5,7,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,8};
    TreeNode* root = buildTree(nums, 0);
    Solution solution;
    root = solution.convertBST(root);
    printTree(root);
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << " ";
    // }
    // cout << endl;
    return 0;
}
