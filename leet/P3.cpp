#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
	int lengthOfLongestSubstring2(string ss) {
		vector<int> dp(256, -1);
		int ret = 0, lo = -1;
		for (int i = 0; i < ss.size(); ++i) {
			if (dp[ss[i]] > lo)
				lo = dp[ss[i]];
			dp[ss[i]] = i;
			ret = max(ret, i - lo);
		}
		return ret;
	}

	int lengthOfLongestSubstring(string ss) {
		unordered_map<char, int> mp;
		int ret = 0, lo = 0;
		for (int i = 0, lo = 0; i < ss.size(); ++i) {
			if (mp.count(ss[i])) {
				lo = max(lo, mp[ss[i]] + 1);
			}
		  mp[ss[i]] = i;
			ret = max(ret, i - lo + 1);	
		}
		return ret;
	}

	int lengthOfLongestSubstring1(string ss) {
		unordered_map<char, int> mp;
		int ret = 0; 
		int cnt = 0;
		for (int i = 0; i < ss.size(); ++i) {
			if (!mp.count(ss[i])) {
				++cnt;
				ret = max(ret, cnt);
				mp[ss[i]] = i;
			}	else {
				i = mp[ss[i]];	
				mp.clear();
				cnt = 0;
			}
		}
		return ret;
	}

	int lengthOfLongestSubstring3(string ss) {
		int res = 0;
		unordered_set<int> st;
		int lo = 0, i = 0;
		while (i < ss.size()) {
			if (!st.count(ss[i])) {
				st.insert(ss[i++]);
				res = max(res, (int)st.size());
			}	else {
				st.erase(ss[lo++]);
			}
		}
		return res;
	}
};

void test(string inp, int right) {
	Solution go;
	int res = go.lengthOfLongestSubstring(inp);
	assert(res == right);
}

int main(int argc, char **argv) {
	test("abcabcbb", 3);
	test("bbbb", 1);
	test("pwwkew", 3);
	test("dvdf", 3);
	test("abba", 2);
	return 0;
}
