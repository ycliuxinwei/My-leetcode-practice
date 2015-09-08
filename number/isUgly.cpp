#include <iostream>
using namespace std;

/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/
bool isUgly(int num) {
	if(num==0) return false;
	while(true) {
		if(num%2==0) num /= 2;
		else if(num%3==0) num /= 3;
		else if(num%5==0) num /= 5;
		else break;
	}
	return num==1;
}

void print(bool a) {
	if(a) cout << " is an ugly number";
	else cout << " is not an ugly number";
	cout << endl;
}

int main() {

	int a = 30, b = 34, c = 24, d = 88;
	cout << a; print(isUgly(a));
	cout << b; print(isUgly(b));
	cout << c; print(isUgly(c));
	cout << d; print(isUgly(d));

	return 0;
}