// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for (string word : words) {
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};

int main() {
    string s = "the sky is blue";
    cout << Solution().reverseWords(s) << endl;
    return 0;
}
