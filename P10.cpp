#include <iostream>
#include <stdio.h>

using namespace std;

bool isMatch(string s, string regx) {
	if (s == regx) return true;
	 
}

int main() 
{
	cout << isMatch("aa","a") << endl;
	cout << isMatch("aa","aa") << endl;
	cout << isMatch("aaa","aa") << endl;
	cout << isMatch("aa", "a*") << endl;
	cout << isMatch("aa", ".*") << endl;
	cout << isMatch("ab", ".*") << endl;
	cout << isMatch("aab", "c*a*b") << endl;
	return 0;
}
