// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        for (const auto &token : tokens) {
            if (token == "+") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a + b);
            } else if (token == "-") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a - b);
            } else if (token == "*") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a * b);
            } else if (token == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a / b);
            } else {
                stk.push(std::stoi(token));
            }
        }
        return stk.top();
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tokens1{"2", "1", "+", "3", "*"};
    std::cout << sol.evalRPN(tokens1) << std::endl; // Output: 9

    std::vector<std::string> tokens2{"4", "13", "5", "/", "+"};
    std::cout << sol.evalRPN(tokens2) << std::endl; // Output: 6

    std::vector<std::string> tokens3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << sol.evalRPN(tokens3) << std::endl; // Output: 22

    return 0;
}
