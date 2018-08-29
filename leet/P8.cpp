#include<bits/stdc++.h>
using namespace std;

int myAtoi(string ss) {
	if (ss.size() <= 0) return 0;
	int sign = 1, sflag = 0;
	ll ret = 0;
	// skip white space
	while (ss[i] == ' ') ++i;	 
	for (int i = 0; i < ss.size(); ++i) {
		if (((ss[i]>='0' && ss[i]<='9') || ss[i] == '-' || ss[i] == '+')) {
			if (ss[i] == '-' || ss[i] == '+') {
				sign = (ss[i] == '-' ? -1: 1); 
				sflag++;
			}
			// Only one sign symbol is allowed.
			if (sflag > 1) return 0; 

			if (ss[i] != '-' && ss[i] != '+')
				ret = ret * 10 + (ss[i] - '0');

			if (ret * sign > INT_MAX) {
				ret = INT_MAX; 
				return ret;
			}

			if (ret * sign < INT_MIN) {
				ret = INT_MIN; return ret;
			}
		} else break;
	}		
	return ret * sign;
}

void test(string inp) {
	Solution go;
	int res = go.myAtoi(inp);
	output(1, res);
}

int main() {
	test("12.34");
	test("  12.34");
	test("  -12.34");
	test("  -012.34");
	test(" --012.34");
	test(" a12.34");
	test("2147483648");
	test("9223372036854775809");
	return 0;
}
