// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();
        if (n != m) return nullptr;

        std::unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }

        return buildTree(inorder, 0, n-1, postorder, 0, m-1, map);
    }

private:
    TreeNode* buildTree(std::vector<int>& inorder, int il, int ir, 
                        std::vector<int>& postorder, int pl, int pr, 
                        std::unordered_map<int, int>& map) {
        if (il > ir || pl > pr) return nullptr;
        
        int root_val = postorder[pr];
        TreeNode *root = new TreeNode(root_val);

        int k = map[root_val];
        int num_left = k - il;

        root->left = buildTree(inorder, il, k-1, postorder, pl, pl+num_left-1, map);
        root->right = buildTree(inorder, k+1, ir, postorder, pl+num_left, pr-1, map);

        return root;
    }
};

int main(){
    Solution s;
    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};
    s.buildTree(inorder, postorder);
    return 0;
}