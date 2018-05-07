#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int myAtoi(string s) {
	if (s.size() <= 0) return 0;
	int sign = 1;
	int ret = 0;
	int i=0;
	int sflag = 0;
	while (s[i] == ' ') ++i;	// skip white space 
	while (i < s.size()) {
		if (((s[i]>='0' && s[i]<='9') || s[i] == '-' || s[i] == '+')) {
			if (s[i] == '-' || s[i] == '+') {sign = (s[i] == '-' ? -1: 1); sflag++;}
			if (sflag != 1 && sflag != 0 ) return 0; // only one sign symbol

			if (ret*sign > (INT_MAX-(s[i]-'0')) / 10) return INT_MAX; 
			if (ret*sign < (INT_MIN+(s[i]-'0')) / 10) return INT_MIN; 
			if (s[i] != '-' && s[i] != '+')
			// NOTE: if (isdigit(s[i])  cctype header file
				ret = ret*10 + (s[i] - '0');
			//if (ret*sign > INT_MAX) {ret = INT_MAX; return ret;}
			//if (ret*sign < INT_MIN) {ret = INT_MIN; return ret;}
			i++;
		} else break;
	}		
	return ret * sign;
}

int main() {
	cout << myAtoi("12.34") << endl;
	cout << myAtoi("  12.34") << endl;
	cout << myAtoi("  -12.34") <<endl;
	cout << myAtoi("  -012.34") <<endl;
	cout << myAtoi(" --012.34") <<endl;
	cout << myAtoi(" a12.34") << endl;
	cout << myAtoi("2147483648") << endl;
	cout << myAtoi("9223372036854775809") << endl;
	return 0;
}
