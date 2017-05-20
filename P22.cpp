#include <stdio.h>
#include <stdlib.h> // for atoi
#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s) {
	char stack[s.size()];
	int k = 0;
	for (int i=0; i<s.size(); ++i) {
		if (s[i] == '(') stack[k++] = s[i];
		else if(s[i] == ')') {
			if (k < 1) return false;
			char c = stack[k-1];
			if (c == '(' && s[i] == ')')
				--k;
			else return false;
		}
	}
	if (k == 0) return true;
	cout << k << endl;
	return false;
}

void bt(int n, int lsum, int rsum, string ans, vector<string>& ret) {
	if (lsum == n && rsum == n) {
		cout << ans << endl;
		if (isValid(ans)) 
			ret.push_back(ans);
		return;
	} else if (lsum>n || rsum>n) {
		return ;
	}else {
		ans.push_back('(');
		bt(n, lsum+1, rsum, ans, ret);
		ans.pop_back();
		ans.push_back(')');
		bt(n, lsum, rsum+1, ans, ret);
		ans.pop_back();
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ret;
	bt(n, 1, 0, "(", ret);	
	return ret;
}

void printVector(vector<string> v) {
	cout << "[" << endl;
	for (auto s: v) {
		cout << s << "," << endl;
	}
	cout << "]" << endl;
}

int main(int argc, char **argv) {
	cout << isValid("()(())") << endl;
	int n = 3;
	if (argc > 1) {
		n = atoi(argv[1]);
	}
	printVector(generateParenthesis(n) );
	return 0;
}

