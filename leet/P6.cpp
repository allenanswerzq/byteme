#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
string convert1(string s, int n) {
	if (n<=1 || n>=s.size()) return s;
	
	vector<string> r(n);
	int row = 0;
	int step = 1;
	for (int i=0; i<s.size(); ++i) {
		if (row == n-1) step = -1;
		if (row == 0) step = 1;
		r[row] += s[i];
		row += step;
	}	

	string result;
	for (auto c: r)
		result += c;
	return result;
}

string convert(string s, int n) {
	if (n<=1 || n>=s.size()) return s;
	map<int, string> m;
	int i = 0, k = 0;
	int step = 1;
	// bool flag = true;
	while (k < s.length()) {
		//m[i].push_back(s[k++]);
		m[i] += s[k++];
		if (i == n-1) step = -1;
		if (i == 0) step = 1;
		i += step;
		/*
		if (flag) {
			++i;
			if (i == n) { i = n-2; flag = false; }
		} else {
			--i;
			if (i == -1) {i = 1; flag = true;}
		}*/
	}

	string ret;
	for (int i=0; i<n; ++i) {
		/*vector<char> v = m[i];
		for (auto c : v)
			ret += c;
			*/
		ret += m[i];
	}
	return ret;
}

int main() {
	cout << convert("PAYPALISHIRING", 3) << endl;
	cout << convert("PAYPALISHIRING", 4) << endl;
	cout << convert("AB", 1) << endl;
	return 0;
}
