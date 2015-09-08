#include <string>
#include <iostream>
using namespace std;

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, Given s = "Hello World", return 5.
*/
int lengthOfLastWord(string s) {
	int n = s.size();
	int count = 0;
	for(int i = n-1; i>=0; i--)
		if(s[i]!=' ') count++;
		else if(count) break;
		else continue;
	return count;
}

int main() {

	string str1 = "Hello World";
	cout << lengthOfLastWord(str1) << endl;

 	string str2 = "Hello World ";
	cout << lengthOfLastWord(str2) << endl;

	string str3 = "  ";
	cout << lengthOfLastWord(str3) << endl;

	return 0;
}