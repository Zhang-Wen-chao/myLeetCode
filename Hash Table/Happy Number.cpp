// 202. Happy Number
// https://leetcode.com/problems/happy-number/
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.count(n) == 0) {
            seen.insert(n);
            int next = 0;
            while (n > 0) {
                int d = n % 10;
                next += d * d;
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    return 0;
}
