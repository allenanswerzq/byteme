#include<bits/stdc++.h>

using namespace std;
// binary search
// divide and conquer
// horizontal scan
// vertical scan
// Accepted
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() <= 0) return "";
	int minLen = INT_MAX; // NOTE: initialize value
	map<char, int> m;
	string ret = "";
	for (int i=0; i<strs.size(); ++i)
		minLen = min(minLen, (int)strs[i].length());

	cout << minLen << endl;
	for (int j=0; j<minLen; ++j) {
		char t;
		for (int i=0; i<strs.size(); ++i) {
			t = strs[i][j];
			m[strs[i][j]]++;
		}	
		if (m.size() == 1 && m[t] == strs.size()){
			m.clear();
			ret += t;
		}
		else return ret;
	}

	return ret;
}

int main() {
	vector<string> strs({"aaaa", "", "acc"});
	cout << longestCommonPrefix(strs);
	vector<string> aa({"aa", "aa"});
	cout << longestCommonPrefix(aa);
	return 0;
}
