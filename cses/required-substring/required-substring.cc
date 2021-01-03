/* created   : 2021-01-01 21:52:37
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<int> prefix_function(const string& s) {
  //           -----....-----
  //           [-j-]
  // [-j-]
  // -----j....-----i
  // -----.....-----++++++++++++++++++++
  int n = (int) s.size();
  vector<int> next(n);
  for (int i = 1; i < n; i++) {
    int j = next[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = next[j - 1];
    }
    if (s[i] == s[j]) j++;
    next[i] = j;
  }
  return next;
}

const int mod = 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mul(int a, int b) { return (int)((ll)a * b % mod); }


void solve() {
  int N; cin >> N;
  string S; cin >> S;
  vector<int> next = prefix_function(S);
  trace(N, S, next);
  int m = S.size();
  vector<vector<int>> f(N + 1, vector<int>(m + 1));
  // f[i][j]:
  // N: 0__________i-1-----
  // S:      0_____j-1_____
  //
  f[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < m; j++) {
      for (char c = 'A'; c <= 'Z'; c++) {
        int k = j;
        while (k > 0 && S[k] != c) {
          k = next[k - 1];
        }
        if (S[k] == c) {
          k++;
        }
        add(f[i + 1][k], f[i][j]) ;
      }
    }
  }
  // trace(f);
  int ans = 0;
  int val = 1;
  // ........S0, S1, S2,,,Sn ....
  for (int i = N; i >= m; i--) {
    add(ans, mul(f[i][m], val));
    val = mul(val, 26);
  }
  trace(ans < mod);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
