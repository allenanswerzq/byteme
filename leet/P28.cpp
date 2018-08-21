#include<bits/stdc++.h>

using namespace std;

int strStr1(string whole, string part) {
	int found = whole.find(part);
	if (found != string::npos)
		return found;
	else return -1;
}

int strStr2(string whole, string part) {
	if (whole == part || part == "") return 0;
	int m = whole.size(), n = part.size();
	int k = 0;
	for (int i=0; i<m-n+1; ++i) {
		if (whole[i] != part[k]) continue;
		// store last equal pos
		int last = i; 
		//cout << last << endl;
		while (k<part.size() && i<whole.size()) {
			if (whole[i] == part[k]) {
				i++;
				k++;
			}
			else break;
		}
		if (k == part.size()) return last;
		else {i = last; k = 0;} 
	}
	return -1;
}

int strStr(string whole, string part) {
	int m = whole.size(), n = part.size();
	if (n == 0) return 0;
	for (int i=0; i<m-n+1; ++i) {
		int j = 0;
		for (; j<n; ++j) {
			if (whole[i+j] != part[j]) break;
		}
		if (j == n) return i;
	}
	return -1;
}

int main(){
	//cout << strStr("", "") << endl;
	//cout << strStr("abcbcde", "bcde") << endl;
	cout << strStr("mississippi", "issip") << endl;
	return 0;
}

