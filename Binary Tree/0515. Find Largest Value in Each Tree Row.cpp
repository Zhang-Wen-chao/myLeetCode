// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int size = queue.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            result.push_back(maxVal);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    
    vector<int> result = solution.largestValues(root);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
