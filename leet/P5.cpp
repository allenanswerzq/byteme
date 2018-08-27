#include<bits/stdc++.h>
using namespace std;

// IDEAS:
// brute force: time complexity O(n3)
// expand around center: time complexity O(n2)
// dp: time complexity O(n2)
//
string longestPalindrome(string s) {
	// dp approach
	// dp(i, j) = true if dp(i+1, j-1) && s[i] == s[j]
	// base cases:
	// dp(i, i) = true; dp(i, i+1) = (s[i] == s[i+1])
	int len = s.size();
	int dp[len][len]; 
	int start = 0, maxLen=0;
	
	for (int i=0; i<len; ++i)
		dp[i][i] = 1;  									// length equals 1
	for (int i=0; i<len-1; ++i)
		dp[i][i+1] = (s[i] == s[i+1]); 	// length equals 2	
	
	for (int k=2; k<len; ++k) 				// length form 3 to N
		for (int i=0; i<len; ++i) {
			int j = i + k;
			if ( j < len) 
				dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));	
		}	

	for (int i=0; i<len; ++i) {
		for (int j=0; j<len; ++j){
			if (dp[i][j] && maxLen < j-i+1) {
				maxLen = j-i+1;
				start = i;
			}	
		}
	}

	return s.substr(start, maxLen);	
}

vector<int> fastLongestPalindromes(string str) {
  int i=0,j,d,s,e,lLen,palLen=0;
  vector<int> res;
  while (i < str.length()) {
    if (i > palLen && str[i-palLen-1] == str[i]) {
      palLen += 2; i++; continue;
    }
    res.push_back(palLen);
    s = res.size()-2;
    e = s-palLen;
    bool b = true;
    for (j=s; j>e; j--) {
      d = j-e-1;
      if (res[j] == d) { palLen = d; b = false; break; }
      res.push_back(min(d, res[j]));
    }
    if (b) { palLen = 1; i++; }
  }
  res.push_back(palLen);
  lLen = res.size();
  s = lLen-2;
  e = s-(2*str.length()+1-lLen);
  for (i=s; i>e; i--) { d = i-e-1; res.push_back(min(d, res[i])); }
  return res;
}

#define pvi(x) for(auto &e : x) cout << e << " "; cout << endl

int main() {
	// cout << longestPalindrome("babad") << endl;
	// cout << longestPalindrome("cbbd") << endl;
	// cout << longestPalindrome("abcba") << endl;

	vector<int> res = fastLongestPalindromes("babad");
	pvi(res);
	res = fastLongestPalindromes("cbbde");
	pvi(res);
	return 0;
}
