// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};

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
int main() {
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = Solution().sortedArrayToBST(nums);
    printTree(root);
    return 0;
}
