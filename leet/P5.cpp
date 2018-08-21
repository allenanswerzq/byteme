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
	// NOTE: how to initialize dp equals 0	
	int dp[len][len] = {}; 
	int start = 0, maxLen=0;
	
	// base cases:
	for (int i=0; i<len; ++i)
		dp[i][i] = 1;  									// length equals 1
	for (int i=0; i<len-1; ++i)
		dp[i][i+1] = (s[i] == s[i+1]); 	// length equals 2	
	
	// NOTE: how to calcuate dp
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

int main() {

	cout << longestPalindrome("babad") << endl;
	cout << longestPalindrome("cbbd") << endl;
	cout << longestPalindrome("abcba") << endl;
	return 0;
}
