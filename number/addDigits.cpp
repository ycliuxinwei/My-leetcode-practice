#include <iostream>
using namespace std;

/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example: Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up: Could you do it without any loop/recursion in O(1) runtime?

Hint: A naive implementation of the above process is trivial. Could you come up with other methods?
*/
// loop
int addDigits(int num) {
	while(num > 9) num = num/10 + num%10;
	return num;
}

// recursion
int addDigits1(int num) {
	if(num<10) return num;
	int tmp = 0;
	while(num>9){
		tmp += num%10;
		num = num/10;
	}
	tmp += num;
	addDigits1(tmp);
}

// math
int addDigits2(int num) {
	return (num - 1) % 9 + 1;
}

int main() {

	int num = 33458;
	cout << addDigits(num) << endl;
	cout << addDigits1(num) << endl;
	cout << addDigits2(num);

	return 0;
}