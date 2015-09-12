/* Copyright 2015 Edmund Liu

Given a string, find the length of the longest sub-string without repeating characters. For example, the longest sub-string without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest sub-string is "b", with the length of 1.

*/
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n < 2) return n;
    map<char, int> dict;
    int begin = 0, result = 0;
    for (int i = 0; i < n; i++) {
        if (dict.find(s[i]) != dict.end())
            begin = max(begin, dict[s[i]]+1);
        result = max(i-begin+1, result);
        dict[s[i]] = i;
    }
    return result;
}

int main() {
    string s0 = "acebdr";
    cout << lengthOfLongestSubstring(s0);
    string s1 = "vqblqcb";
    cout << lengthOfLongestSubstring(s1);
    string s2 ="abba";
    cout << lengthOfLongestSubstring(s2);
    string s3 ="abcabcbb";
    cout << lengthOfLongestSubstring(s3);
    string s4 ="tmmzuxt";
    lengthOfLongestSubstring(s4);
    return 0;
}
