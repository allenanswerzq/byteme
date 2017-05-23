#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

bool isExist(vector<string>& words, vector<int>& m, string tmp) {
	for (int i=0; i<words.size(); ++i) {
		if (tmp == words[i] && m[i] == 0) {
			m[i] = 1;
			return true;
		}
	}
	return false;
}
// Time limit exceeded
// ugly code `
vector<int> findSubstring(string s, vector<string>& words) {
	int l = s.size(), n = words[0].size();
	vector<int> ret;
	map<string, int> m;	
	for (int i=0; i<words.size(); ++i) 
		if (m.find(words[i]) == m.end())
			m[words[i]] = 1;
		else
			m[words[i]]++;

	for (int i=0; i<=l-n; i++) {
		int winLeft = i;
		string tmp = s.substr(i, n);
		int k = 0;
		while (isExist(words, m, tmp)) {
			k++;
			i += n;
			tmp = s.substr(i, n);
		}
		if (k == words.size()) ret.push_back(winLeft);
		i = winLeft;
	}	
	return ret;
}

void printVector(vector<int> v) {
	cout << "[";
	for (int x :v ) 
		cout << x << " ";
	cout << "]" << endl;
}

int main() {
	vector<string> words({"foo", "bar"});
	printVector( findSubstring("barfoothefoobarman", words) );
	vector<string> v({"foo", "bar", "the"});
	printVector( findSubstring("barfoothefoobarman", v) );
	vector<string> vv({"foo", "bar"});
	printVector( findSubstring("barfoofoothefoobarman", vv) );
	vector<string> vvv({"word","good","best","good"});
	printVector( findSubstring("wordgoodgoodgoodbestword", vvv) );
	vector<string> vvvv({"fooo","barr","wing","ding","wing"});
	printVector( findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", vvvv) );
	return 0;
}
