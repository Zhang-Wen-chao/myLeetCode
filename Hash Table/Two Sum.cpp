// 001. Two Sum
// https://leetcode.cn/problems/two-sum/
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement) != 0) {
                return { map[complement], i };
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}