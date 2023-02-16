// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        std::unordered_map<char, char> map{{')', '('}, {'}', '{'}, {']', '['}};

        for (const auto &c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != map[c]) {
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution sol;
    std::cout << sol.isValid("()") << std::endl; // Output: true
    std::cout << sol.isValid("()[]{}") << std::endl; // Output: true
    std::cout << sol.isValid("(]") << std::endl; // Output: false
    std::cout << sol.isValid("([)]") << std::endl; // Output: false
    std::cout << sol.isValid("{[]}") << std::endl; // Output: true
    return 0;
}
