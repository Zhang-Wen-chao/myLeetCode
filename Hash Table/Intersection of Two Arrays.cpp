// 349. Intersection of Two Arrays
// https://leetcode.cn/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> res;
    for (int i : set1) {
        if (set2.count(i)) {
            res.push_back(i);
            set2.erase(i);
        }
    }

    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res = intersect(nums1, nums2);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
