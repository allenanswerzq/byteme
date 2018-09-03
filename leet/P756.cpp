#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
		int map[26][26];
		int dp[2][10];
  bool pyramidTransition(string bottom, vector<string>& allowed) {
  	int n = bottom.size();
  	for (auto s: allowed)
  		map[s[0]-'A'][s[1]-'A'] |= 1<<(s[2]-'A');
  	for (int i=0; i<n; ++i) 
  		dp[0][i] = 1<<(bottom[i]-'A');
  	int cur=0, nxt=1;
  	for (int i=1; i<n; ++i) {
  		for (int j=0; j<n-i; ++j) {
  			for (int k1=0; k1<7; k1++)	
  				for (int k2=0; k2<7; k2++) {
  					if ((dp[cur][j]>>k1)&1	&& (dp[cur][j+1]>>k2)&1)
  						dp[nxt][j] |= map[k1][k2];
  				}
  		}
  		swap(cur, nxt);
  	}
  	return dp[cur][0]!=0;   
  }
};

class Solution {
public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
 		map<string, vector<char>> mp;       
 		vector<vector<set<char>>> dp(n, vector<set<char>>(n));
 		for (auto s: allowed)
 			mp[s.substr(0, 2)].push_back(s[2]); 
 		int n = bottom.size();
 		for (int i=0; i<n; ++i)
 			dp[0][i].insert(bottom[i]);
 		// from level to level stack 
 		for (int i=1; i<n; ++i)
 			for (int j=0; j<n-i; j++) 
 				for (char c1: dp[i-1][j]) 
 					for (char c2: dp[i-1][j+1]) {
 						string now = "";
 						now = now + c1 + c2;
 						for (auto c: mp[now])
 							dp[i][j].insert(c);
 					}
 		return !dp[n-1][0].empty();
  }
};
