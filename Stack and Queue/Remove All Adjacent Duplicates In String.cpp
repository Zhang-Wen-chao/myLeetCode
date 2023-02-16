// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};

int main() {
    Solution sol;
    std::cout << sol.removeDuplicates("abbaca") << std::endl; // Output: "ca"
    std::cout << sol.removeDuplicates("aaabaaaa") << std::endl; // Output: ""
    std::cout << sol.removeDuplicates("abbbabbaca") << std::endl; // Output: "c"
    return 0;
}