#include<bits/stdc++.h>
using namespace std;

// good stack problem
int calculate(string s) {
	stack<int> stk;
	int sign = 1, res = 0;
	for (int i=0; i<s.size(); ++i) {
		if (s[i] >= '0') {
			int num = 0;
			while (i<s.size() && s[i]>='0')
				num = num*10 + s[i++]-'0';
			--i;
			res += sign * num;
		} 
  else if (s[i] == '+') sign = 1;
		else if (s[i] == '-') sign = -1; 
		else if (s[i]=='(') {
			stk.push(res);
			stk.push(sign);
			res = 0;
			sign = 1;
		} else if (s[i]==')') {
			int s = stk.top(); stk.pop();
			int t = stk.top(); stk.pop();
			res = t + s * res;
		}
	}
	return res;
}
