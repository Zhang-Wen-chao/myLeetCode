// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sums;
        for (auto a : A) {
            for (auto b : B) {
                ++sums[a + b];
            }
        }
        
        int count = 0;
        for (auto c : C) {
            for (auto d : D) {
                auto it = sums.find(-c - d);
                if (it != sums.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout << s.fourSumCount(A, B, C, D) << endl;
    return 0;
}