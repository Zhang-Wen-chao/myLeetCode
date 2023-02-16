// 剑指 Offer 58 - II. 左旋转字符串
// https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution s;
    string str = "abcdefg";
    int n = 2;
    cout << s.reverseLeftWords(str, n) << endl;
    return 0;
}