#include<bits/stdc++.h>

using namespace std;
// NOTE:
// dp(N, i, j) = sum{ dp(N-1, adjacent cell) } 
int findPaths1(int m, int n, int N, int i, int j) {
  while (N-- > 0)
  int dp[51][50][50] = {};
  for (auto Ni = 1; Ni <= N; ++Ni)
  for (auto mi = 0; mi < m; ++mi)
  for (auto ni = 0; ni < n; ++ni)
  dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1? 1 : dp[Ni - 1][mi + 1][ni])
    + (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) % 1000000007;
  return dp[N][i][j];
}         
   
int findPaths(int m, int n, int N, int i, int j) {
  int g[2][50][50] = {};
  while (N-- > 0) // Cant understand this
  for (auto k = 0; k < m; ++k)
  for (auto l = 0; l < n; ++l)
  g[(N + 1) % 2][k][l] = ((k == 0 ? 1 : g[N % 2][k - 1][l]) + (k == m - 1? 1 : g[N % 2][k + 1][l])
    + (l == 0 ? 1 : g[N % 2][k][l - 1]) + (l == n - 1 ? 1 : g[N % 2][k][l + 1])) % 1000000007;
  return g[1][i][j];// why 1???
}         
   
int main() {

	cout << findPaths(2, 2, 2, 0, 0) << endl;
	cout << findPaths(1, 3, 3, 0, 1) << endl;
	return 0;
}
