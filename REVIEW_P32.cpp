#include <stdio.h>
#include <iostream>

using namespace std;

int longestValidParentheses(string s) {
	int n = s.size();
	if (n <= 0) return 0;
	int stack[n];
	int k = 0, ret = 0;
	for (int i=0; i<n; ++i) {
		if (s[i] == '(') 
			stack[k++] = '(';	
		else {
			if (k > 0) {
				k--;
				ret++;
			}
		}
	}
	return 2 * ret;
}

int main() {
	cout << longestValidParentheses("(()") << endl;
	cout << longestValidParentheses("((())()") << endl;
	return 0;
}
