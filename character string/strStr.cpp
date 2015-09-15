/* Copyright 2015 Edmund Liu

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// print the vector
void printVector(const vector<int>& a) {
    cout << "[";
    vector<int>::const_iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

/* Time Limit Exceeded: O(m*n)
int strStr(string haystack, string needle) {
    int haSize = haystack.size();
    int neSize = needle.size();
    if (neSize == 0) return 0;
    int i, j;
    for (i = 0; i < haSize; i++)
        if (haystack[i] == needle[0]) {
            for (j = 1; j < neSize; j++)
                if (haystack[i+j] != needle[j])
                    break;
            if (j == neSize) return i;
        }
    return -1;
} */

// compute Prefix function
vector<int> PrefixFun(string needle) {
    int m = needle.size();
    vector<int> pi(m);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && needle[k] != needle[i])
            k = pi[k-1];
        if (needle[k] == needle[i])
            k = k+1;
        pi[i] = k;
    }
    return pi;
}

// KMP(Knuth-Morris-Pratt) algorithm
int strStr(string haystack, string needle) {
    int haSize = haystack.size();
    int neSize = needle.size();
    if (neSize == 0) return 0;
    vector<int> PF = PrefixFun(needle);
    int i = 0, j = 0, step;
    while (i < haSize) {
        if (haystack[i] == needle[j]) {
            if (j == neSize-1) return i-neSize+1;
            j++; i++;
        }
        else if (j == 0) i++;
        else j = PF[j-1];
    }
    return -1;
}

int main() {
    string haystack = "weabcdefg";
    string needle = "cde";
    cout << strStr(haystack, needle);
    return 0;
}
