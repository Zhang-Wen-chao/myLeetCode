// 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }
    
private:
    TreeNode* deserializeHelper(const string &data, int &pos) {
        int next_comma = data.find(',', pos);
        string value = data.substr(pos, next_comma - pos);
        pos = next_comma + 1;
        if (value == "null") return nullptr;
        TreeNode *node = new TreeNode(stoi(value));
        node->left = deserializeHelper(data, pos);
        node->right = deserializeHelper(data, pos);
        return node;
    }
};

int main() {
    Codec codec;
    string data = "1,2,3,null,null,4,5,null,null,null,null";
    TreeNode *root = codec.deserialize(data);
    cout << codec.serialize(root) << endl;
    return 0;
}
