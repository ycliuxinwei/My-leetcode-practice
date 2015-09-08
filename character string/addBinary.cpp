#include <string>
#include <iostream>
using namespace std;

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
string addBinary(string a, string b) {
	string sum;
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	while(i>=0 || j>=0 || carry==1) {
		carry += i>=0 ? a[i--]-'0' : 0;
		carry += j>=0 ? b[j--]-'0' : 0;
		sum = char(carry%2+'0') + sum;
		carry /= 2;	
	}
	return sum;
}

int main() {

	string str1 = "11";
	string str2 = "11";
	string str3 = addBinary(str1, str2);
	cout << str3;

	return 0;
}