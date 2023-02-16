// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/
#include <iostream>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.size();
    for (int i = n / 2; i >= 1; --i) {
        if (n % i == 0) {
            int k = n / i;
            string sub = s.substr(0, i);
            int j;
            for (j = 1; j < k; ++j) {
                if (sub != s.substr(j * i, i)) break;
            }
            if (j == k) return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (repeatedSubstringPattern(s) ? "True" : "False") << endl;
    return 0;
}
