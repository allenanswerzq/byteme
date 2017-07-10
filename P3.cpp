#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int lengthOfLongestSubstring2(string s) {
	vector<int> d(256, -1);
	int ret = 0, start = -1;
	for (int i=0; i<s.length(); ++i) {
		if (d[s[i]] > start)
			start = d[s[i]]
		d[s[i]] = i;
		ret = max(ret, i - start);
	}
	return ret;
}

int lengthOfLongestSubstring(string s) {
	map<char, int> m;
	int ret = 0;
	for (int i=0, j=0; i<s.size(); ++i) {
		if (m.find(s[i]) != m.end()) {
			j = max(j, m[s[i]]+1);
		}
	   	m[s[i]] = i;
		ret = max(ret, i - j + 1);	
	}
	return ret;
}

int lengthOfLongestSubstring1(string s) {
	map<char, int> m;
	int ret = 0;
	int ans = 0;
	int i = 0;
	while (i < s.size()) {
		if (m.find(s[i]) == m.end()) {
			ans++;
			cout << s[i];
			ret = max(ret, ans);
			m[s[i]] = i;
			i++;
		} else {
			i = m[s[i]] + 1;
			m.clear();
			ans = 0;
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	string s1 = "abcabcbb";
	string s2 = "bbbb";
	string s3 = "pwwkew";
	string s4 = "dvdf";
	string s5 = "abba";
	
	cout << lengthOfLongestSubstring(s1) << endl;
	cout << lengthOfLongestSubstring(s2) << endl;
	cout << lengthOfLongestSubstring(s3) << endl;
	cout << lengthOfLongestSubstring(s4) << endl;
	cout << lengthOfLongestSubstring(s5) << endl;
	
	return 0;
}
