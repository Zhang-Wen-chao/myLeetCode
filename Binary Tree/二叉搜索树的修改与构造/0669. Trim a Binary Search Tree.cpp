// 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/
// #include <iostream>
// #include <vector>

// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if (!root) return NULL;
//         if (root->val < low) return trimBST(root->right, low, high);
//         if (root->val > high) return trimBST(root->left, low, high);
//         root->left = trimBST(root->left, low, high);
//         root->right = trimBST(root->right, low, high);
//         return root;
//     }

//     void preorder(TreeNode *root, vector<string> &res) {
//         if (!root) {
//             res.push_back("#");
//             return;
//         }
//         res.push_back(to_string(root->val));
//         preorder(root->left, res);
//         preorder(root->right, res);
//     }
//     //delete the "#" of last layer

// };

// int main() {
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(0);
//     root->right = new TreeNode(2);

//     Solution solution;
//     TreeNode *new_root = solution.trimBST(root, 1, 2);

//     vector<string> res;
//     solution.preorder(new_root, res);
//     for (auto &i : res) cout << i << " ";
//     cout << endl;

//     return 0;
// }

//牛的，终于给了正确的输出
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

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return NULL;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    void preorder(TreeNode *root, vector<string> &res) {
        if (!root) {
            res.push_back("#");
            return;
        }
        res.push_back(to_string(root->val));
        preorder(root->left, res);
        preorder(root->right, res);
    }

    void removeLastNull(vector<string> &res) {
        int n = res.size();
        int i = n - 1;
        while (i >= 0 && res[i] == "#") i--;
        res.resize(i + 1);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);

    Solution solution;
    TreeNode *new_root = solution.trimBST(root, 1, 2);

    vector<string> res;
    solution.preorder(new_root, res);
    solution.removeLastNull(res);
    for (auto &i : res) cout << i << " ";
    cout << endl;

    return 0;
}
