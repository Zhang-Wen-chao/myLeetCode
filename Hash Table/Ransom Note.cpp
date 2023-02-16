// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> chars;
        for (auto c : magazine) {
            ++chars[c];
        }
        
        for (auto c : ransomNote) {
            if (--chars[c] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    Solution solution;
    cout << (solution.canConstruct(ransomNote, magazine) ? "Yes" : "No") << endl;
    return 0;
}
