#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

bool isPal(string s) {
  if (s == "") return true;
  int lo=0, hi=s.size()-1;
  while (lo < hi) 
    if (s[lo++] != s[hi--])
      return false;
  return true;
}
// Perfect
int countSubstrings(string s) {
  if (s == "") return 0;
  int cnt = 0;
  for (int j=0; j<s.size(); ++j) {
    for (int i=1; i<=s.size()-j; ++i)
       if (isPal(s.substr(j, i))) {
         cnt++;
       }
  }
  return cnt;
}

const int mod = 1e9 + 7;
const int N = 1004;
// dp[i][j] denotes the longest palindrome in the 
// range of [i...j].
int dp[N][N];

int countSubstrings(string& inp) {
  int n = sz(inp);
  int res = 0;
  mst(dp, 0);
  fori (r, 1, n + 1) {
  fori (i, 0, n - r + 1) {
    int j = i + r - 1; 
    dp[i][j] = (inp[i] == inp[j]  && (j - i < 3 || dp[i+1][j-1]));
    if (dp[i][j])
    ++res;
  } 
  }
  return res;
}

int main() {
  return 0;
}
