// 27. Remove Element
// https://leetcode.com/problems/remove-element/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    cout << nums.size() << endl;
    int target = 3;
    int ans = s.removeElement(nums, target);

    cout << ans << endl;

    for (int i = 0; i < ans; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}