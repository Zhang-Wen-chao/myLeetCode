// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<Node*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* node = queue.front();
                queue.pop();
                level.push_back(node->val);
                for (Node* child : node->children) {
                    queue.push(child);
                }
            }
            result.push_back(level);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    Node* root = new Node(1);
    vector<Node*> children;
    children.push_back(new Node(3));
    children.push_back(new Node(2));
    children.push_back(new Node(4));
    root->children = children;
    
    vector<vector<int>> result = solution.levelOrder(root);
    for (vector<int> level : result) {
        for (int i : level) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
