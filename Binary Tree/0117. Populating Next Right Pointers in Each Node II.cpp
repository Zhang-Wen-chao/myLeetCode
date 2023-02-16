// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* leftmost = root;
        while (leftmost) {
            Node* head = leftmost;
            leftmost = NULL;
            Node* prev = NULL;
            while (head) {
                if (head->left) {
                    if (!leftmost) leftmost = head->left;
                    if (prev) prev->next = head->left;
                    prev = head->left;
                }
                if (head->right) {
                    if (!leftmost) leftmost = head->right;
                    if (prev) prev->next = head->right;
                    prev = head->right;
                }
                head = head->next;
            }
        }
        return root;
    }
};

int main() {
    Solution solution;
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    
    Node* result = solution.connect(root);
    
    return 0;
}
