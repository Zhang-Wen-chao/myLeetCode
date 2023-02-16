// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            ans.push_back(num * num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    vector<int> sortedSquares_Double_pointer(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }

};


int main() {
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = s.sortedSquares(nums);
    for (int num: ans) {
        cout << num << " ";
    }
    cout << "Double pointer" << endl;
    ans = s.sortedSquares_Double_pointer(nums);
    for (int num: ans) {
        cout << num << " ";
    }
    return 0;
}