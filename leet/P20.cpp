#include <stdio.h>
#include <iostream>

using namespace std;

bool isValid(string s) {
	if (s.size() <=1 ) return false;
	char Stack[s.size()];	
	int k = 0;
	for (int i=0; i<s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			Stack[k++] = s[i];
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (k<1) return false;
			char c = Stack[k-1];
			if (c == '(' && s[i] == ')' || c=='[' && s[i] == ']' || c=='{' && s[i] == '}')
				--k;
			else
				return false;
		}
	}

	if (k == 0) return true;
	return false;
}

int main() {
	cout << isValid("()[]{}") << endl;
	cout << isValid("([)]") <<endl;
	return 0;
}
