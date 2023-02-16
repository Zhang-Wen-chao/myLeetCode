// 77. Combinations
// https://leetcode.com/problems/combinations/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(n, k, 1, curr, res);
        return res;
    }

private:
    void backtrack(int n, int k, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(n, k, i + 1, curr, res);
            curr.pop_back();
        }
    }
};

int main() {
    int n = 5, k = 2;
    Solution sol;
    vector<vector<int>> res = sol.combine(n, k);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j != res[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    return 0;
}
