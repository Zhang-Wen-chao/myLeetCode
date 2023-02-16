// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res, comb, k, n, 1);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& comb, int k, int target, int start) {
        if (!target && comb.size() == k) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (target < i) return;
            comb.push_back(i);
            backtrack(res, comb, k, target - i, i + 1);
            comb.pop_back();
        }
    }
};

int main() {
    int k, n;
    cin >> k >> n;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum3(k, n);
    cout << "[" << endl;
    for (auto& comb : res) {
        cout << "  [";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i != comb.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    return 0;
}
