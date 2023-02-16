// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/
#include <iostream>
#include <queue>

class MyStack {
    std::queue<int> q1, q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        int res = q1.front();
        q1.pop();

        while (!q2.empty()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }

        return res;
    }

    /** Get the top element. */
    int top() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        int res = q1.front();

        while (!q2.empty()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }

        q1.push(res);

        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.top() << std::endl; // Output: 3
    std::cout << stack.pop() << std::endl; // Output: 3
    std::cout << stack.top() << std::endl; // Output: 2
    std::cout << stack.empty() << std::endl; // Output: false
    return 0;
}
