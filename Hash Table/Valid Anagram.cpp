// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string str = "anagram";
    cout<< s.isAnagram(str, "nagaram") << endl;
    return 0;
}
