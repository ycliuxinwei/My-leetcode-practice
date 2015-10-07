/*Copyright 2015 Edmund

Related to question "Excel Sheet Column Title". Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/


#include <iostream>
using namespace std;

int titleToNumber(string s) {
    int n = s.size(), res = 0;
    for (int i = 0; i < n; i++)
        res = res*26 + s[i]-64;
    return res;
}

int main() {
    cout << "AA: " << titleToNumber("AA") << endl;
    cout << "AAB: " << titleToNumber("AAB") << endl;
    return 0;
}
