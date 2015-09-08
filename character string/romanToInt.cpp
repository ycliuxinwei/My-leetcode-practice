#include <vector>
#include <string>
#include <iostream>
using namespace std;

int dict(const char c) {
	switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
}

/*
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

基本字符	相应阿拉伯数字	
I			1
V			5
X			10
L			50
C			100
D			500
M			1000

1. 相同的数字连写，所表示的数等于这些数字相加得到的数，如：III=3；
2. 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如：VIII=8、XII=12；
3. 小的数字（限于I、X和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：IV=4、IX=9；
4. 正常使用时、连写的数字重复不得超过三次；
5. 在一个数的上面画一条横线、表示这个数扩大1000倍。
*/
int romanToInt(string s) {
	int n = s.size();
	int num = 0;
	for(int i = 0; i < n; i++) {
		if(i > 0 && dict(s[i]) > dict(s[i-1]))
			num += (dict(s[i])-2*dict(s[i-1]));
		else num += dict(s[i]);
	}
    return num;
}

int main() {

	string str1 = "MMMCMXCIX"; // 3999 = 3*1000 - 100 + 1000 - 10 + 100 - 1 + 10
	cout << str1 << ": " << romanToInt(str1) << endl;
	
	string str2 = "MCMLXXXIV"; // 1984 = 1000 - 100 + 1000 + 50 + 3*10 - 1 + 5
	cout << str2 << ": " << romanToInt(str2) << endl;
	
	return 0;
}