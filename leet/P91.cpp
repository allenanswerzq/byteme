#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// NOTE: special case
// when input include 0 
// finally, accepted :-(
int numDecodings(string s) {
  int n = s.size();
  vector<int> dp(n, 0);        
  if (n==0 || s[0]=='0') return 0;
  if (n==1 && s[0]!='0') return 1;
  if (stoi(s.substr(0,2))>26 && s[1]=='0') return 0;
  // intialize dp
  dp[0] = 1, dp[1] = stoi(s.substr(0,2)) <= 26 ? s[1]=='0' ? 1:2 :1;
  for (int i=2; i<n; ++i) {
  if (s[i-1]=='0' && s[i]=='0') return 0;
  if (stoi(s.substr(i-1, 2))>26 && s[i]=='0') return 0;
  if (stoi(s.substr(i-1, 2)) <= 26) {
    if (s[i-1]=='0') dp[i]=dp[i-1];
    else if(s[i]=='0') dp[i]=dp[i-2];
    else dp[i] = dp[i-1] + dp[i-2];
  } else {
    dp[i] = dp[i-1];
  }
  //dp[i] = dp[i-1] + dp[i-1] - (dp[i-1] - dp[i-2]);
  }
  return dp[n-1];
}


int main(int argc, char** argv) {
  cout << numDecodings("123") << endl;
  cout << numDecodings("110") << endl;
  cout << numDecodings("10") << endl;
  cout << numDecodings("0") << endl;
  cout << numDecodings("301") << endl;
  cout << numDecodings("27") << endl;
  return 0;
}
