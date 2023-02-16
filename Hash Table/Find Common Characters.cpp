// 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word: words) {
            fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');// emplace_back(n,m)尾端插入n个m
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"bella","label","roller"};
    vector<string> ans = s.commonChars(words);
    for (auto& str: ans) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}