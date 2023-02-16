// 701. Insert into a Binary Search Tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};

std::vector<int> getTreeArray(TreeNode *root) {
    std::vector<int> result;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *node = q.front();
            q.pop();
            result.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

int main() {
    Solution sol;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;

    TreeNode *result = sol.insertIntoBST(root, val);

    std::vector<int> arr = getTreeArray(result);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// #include<iostream>
// #include<vector>
// #include<string>
// #include<queue>
// using namespace std;
// #define null 65535
// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode(int x) { //结构体的构造函数 
// 		val = x;
// 		left = NULL;
// 		right = NULL;
// 	}
// };
// TreeNode* CreateTree(vector<int>Data) {
// 	vector<string>str_data(Data.size(), "");
// 	for (int i = 0; i < Data.size(); i++) {
// 		if (Data[i] != null)
// 			str_data[i] = to_string(Data[i]);
// 		else
// 			str_data[i] = "null";
// 	}
// 	queue<TreeNode*>q;
// 	TreeNode* head = new TreeNode(stoi(str_data[0]));
// 	q.push(head);
// 	int i = 1;
// 	while (i < str_data.size()) {
// 		TreeNode* tmp = q.front();
// 		q.pop();
// 		if (str_data[i] != "null") {
// 			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
// 			tmp->left = new_node;
// 			q.push(new_node);
// 		}
// 		i++;
// 		if (str_data[i] != "null") {
// 			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
// 			tmp->right = new_node;
// 			q.push(new_node);
// 		}
// 		i++;
// 	}
// 	return head;
// }
// void prePrint(TreeNode* Root) {//先序遍历
// 	if (Root == NULL) return;
// 	cout << Root->val << ',';
// 	prePrint(Root->left);
// 	prePrint(Root->right);
// 	return;
// }
// void postPrint(TreeNode* Root) {//后序遍历
// 	if (Root == NULL) return;
// 	postPrint(Root->left);
// 	postPrint(Root->right);
// 	cout << Root->val << ',';
// 	return;
// }
// void inPrint(TreeNode* Root) {//中序遍历
// 	if (Root == NULL) return;
// 	inPrint(Root->left);
// 	cout << Root->val << ',';
// 	inPrint(Root->right);
// 	return;
// }
// int main() {
// 	vector<int>Data = { 1,2,3,null,4,5,6,7,null };
// 	TreeNode* Root = NULL;
// 	Root = CreateTree(Data);
// 	cout << "PreOrder:" << endl;
// 	prePrint(Root);
// 	cout << endl << "InOrder:" << endl;
// 	inPrint(Root);
// 	cout << endl << "PostOrder:" << endl;
// 	postPrint(Root);
// 	getchar();
// }