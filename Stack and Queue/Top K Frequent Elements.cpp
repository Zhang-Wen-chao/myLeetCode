// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;
        for (auto &f : freq) {
            pq.push(f.second);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        for (auto &f : freq) {
            if (f.second >= pq.top()) {
                res.push_back(f.first);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = sol.topKFrequent(nums, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
