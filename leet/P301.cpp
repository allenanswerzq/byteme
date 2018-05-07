#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

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

vector<string> removeInvalidParentheses(string s) {
	unordered_set<string> ret;
	for (int i=0; i<s.size(); ++i) {
		string t = s;
		t.erase(i, 1);
		if (isValid(t)) ret.insert(t);
	}	
	return vector<string> (ret.begin(), ret.end());
}

void printVector(vector<string> v) {
	cout << "{ ";
	for (auto& s: v) {
		cout << s <<"; ";
	}
	cout << " }" << endl;
}
int main() {
	printVector( removeInvalidParentheses("()())()" ));
	printVector( removeInvalidParentheses("(a)())()" ));
	printVector( removeInvalidParentheses(")(" ));
	return 0;
}

