#include <iostream>
#include <string>
using namespace std;

bool isnumical(char c) {
	if((c>=48 && c<=57)||(c>=65 && c<=90)||(c>=97 && c<=122))
		return true;
	return false;
}

char toLower(char c) {
	if(c>=65 && c<=90)
		c = c+32;
	return c;
}

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example, "A man, a plan, a canal: Panama" is a palindrome. "race a car" is not a palindrome.

Note:
1. Have you consider that the string might be empty? This is a good question to ask during an interview.
2. For the purpose of this problem, we define empty string as valid palindrome.
*/
bool isPalindrome(string s) {
	if(s.size()==0) return true;
	if(s==" ") return true;
	string::iterator it = s.begin();
	while(it!=s.end()) {
		if(!isnumical(*it))
			it = s.erase(it);
		else it++;
	}
	if(s.size()==0) return false;
	it = s.begin();
	string::reverse_iterator lt = s.rbegin();
	while(it!=s.end()) {
		if(toLower(*it)!=toLower(*lt))
			return false;
		it++; lt++;
	}
    return true;
}

bool isPalindrome2(string s) {
	int start = 0, end = s.size()-1;
	while(start<end) {
		if(!isalnum(s[start])) start++;
		else if(!isalnum(s[end])) end--;
		else if(tolower(s[start++])!=tolower(s[end--])) return false;
	}
	return true;
}

int main() {
	string str = "A man, a plan, a canal: Panama";
	cout << str << endl;
	
	if(isPalindrome2(str)) cout << "It's a palindrome" << endl;

	if(isPalindrome(str)) cout << "It's a palindrome" << endl;
	
	return 0;
}