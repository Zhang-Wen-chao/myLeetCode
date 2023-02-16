// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    for (int i = 0; i <= (int) haystack.size() - (int) needle.size(); i++) {
        int j = 0;
        for (; j < needle.size(); j++)
            if (haystack[i + j] != needle[j])
                break;
        if (j == needle.size()) return i;
    }
    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "lo";
    cout << strStr(haystack, needle) << endl;
    return 0;
}
