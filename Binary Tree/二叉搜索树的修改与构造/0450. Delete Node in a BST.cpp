// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
// #include <iostream>
// #include <vector>
// #include <queue>

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (!root) return root;
//         if (key < root->val) root->left = deleteNode(root->left, key);
//         else if (key > root->val) root->right = deleteNode(root->right, key);
//         else {
//             if (!root->left) return root->right;
//             if (!root->right) return root->left;
//             TreeNode *minNode = root->right;
//             while (minNode->left) minNode = minNode->left;
//             root->val = minNode->val;
//             root->right = deleteNode(root->right, minNode->val);
//         }
//         return root;
//     }

//     TreeNode* createBST(std::vector<int> &nums, int left, int right) {
//         if (left > right) return NULL;
//         int mid = (left + right) / 2;
//         TreeNode *root = new TreeNode(nums[mid]);
//         root->left = createBST(nums, left, mid - 1);
//         root->right = createBST(nums, mid + 1, right);
//         return root;
//     }
// };

// std::vector<int> getTreeArray(TreeNode *root) {
//     if (!root) return std::vector<int>();
//     std::vector<int> result;
//     std::queue<TreeNode *> q;
//     q.push(root);
//     while (!q.empty()) {
//         int n = q.size();
//         for (int i = 0; i < n; i++) {
//             TreeNode *node = q.front();
//             q.pop();
//             result.push_back(node->val);
//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }
//     }
//     return result;
// }

// int main() {
//     Solution sol;

//     std::vector<int> nums = {5, 3, 6, 2, 4, 7};

//     TreeNode *root = sol.createBST(nums, 0, nums.size() - 1);

//     int key = 2;

//     TreeNode *result = sol.deleteNode(root, key);

//     std::vector<int> arr = getTreeArray(result);

//     for (int i = 0; i < arr.size(); i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> printTree(TreeNode* root) {
        if (!root) return {};
        
        int height = getHeight(root);
        int width = (1 << height) - 1;
        std::vector<int> result(width, INT_MIN);
        
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, width / 2});
        
        int i = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                auto [node, index] = q.front();
                q.pop();
                
                result[index] = node->val;
                
                if (node->left) {
                    q.push({node->left, index - width / (1 << (i + 2))});
                }
                if (node->right) {
                    q.push({node->right, index + width / (1 << (i + 2))});
                }
            }
            i++;
        }
        
        int lastIndex = width - 1;
        while (result[lastIndex] == INT_MIN) {
            lastIndex--;
        }
        
        result.resize(lastIndex + 1);
        return result;
    }

private:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(getHeight(root->left), getHeight(root->right));
    }
};

int main() {
    // Input the binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;
    std::vector<int> result = solution.printTree(root);

    // Output the binary tree
    std::cout << "The binary tree is: [";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}

