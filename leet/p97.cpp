#include<bits/stdc++.h>
using namespace std;

class Solution2 {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int a, b, c;
    a = sz(s1), b = sz(s2), c = sz(s3);
    if (a == 0 && b == 0 && c == 0) 
      return true;

    if (a + b != c) 
      return false;

    // if (a && b && c == 0) 
    //   return false;

    bool x = false, y = false;
    if (s1[0] == s3[0])
      x = isInterleave(s1.substr(1), s2, s3.substr(1));

    if (s2[0] == s3[0])
      y = isInterleave(s1, s2.substr(1), s3.substr(1));

    return x || y;
  }
};

const int N = 1000;
bool dp[N][N];

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int a, b, c;
    a = sz(s1), b = sz(s2), c = sz(s3);
    mst(dp, 0);
    if (a + b != c) 
      return false;
    fori (i, 0, a + 1)
      fori (j, 0, b + 1) {
      if (i == 0 && j == 0)
        dp[i][j] = true;

      else if (i==0 && s2[j-1] == s3[j-1])
        dp[i][j] = dp[i][j-1];

      else if (j==0 && s1[i-1] == s3[i-1])
        dp[i][j] = dp[i-1][j];

      else if (s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1])
        dp[i][j] = dp[i-1][j];

      else if (s1[i-1]!=s3[i+j-1] && s2[j-1] == s3[i+j-1])
        dp[i][j] = dp[i][j-1];

      else if ((s1[i-1] == s3[i+j-1]) && (s2[j-1] == s3[i+j-1]))
        dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
      }
      return dp[a][b];
  }
};

void test(string a, string b, string c) {
  Solution go;
  cout << go.isInterleave(a, b, c) << "\n"; 
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test("XXY", "XXZ", "XXZXXXY");
  test("XY" ,"WZ" ,"WZXY");
  test ("XY", "X", "XXY");
  test ("YX", "X", "XXY");
  test ("XXY", "XXZ", "XXXXZY"); 
  return 0;
}























