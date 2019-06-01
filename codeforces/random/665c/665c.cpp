//============================================================================
// Name        : 665c
// Date        : Wed May 22 21:10:16 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve_greedy() {
  string s;
  cin >> s;
  int n = sz(s);
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == s[i]) {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (s[i - 1] != c && (i == n - 1 || c != s[i + 1])) {
          s[i] = c;
          break;
        }
      }
    }
  }
  output(s);
}

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  const int inf = 1e9 + 7;
  vector<vi> dp(n, vi(26, inf));
  vector<vi> pr(n, vi(26, -1));
  dp[0][s[0] - 'a'] = 0;
  for (int i = 1; i < n; ++i) {
    int c = s[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < 26; ++k) {
        int cost = k == c ? 0 : 1;
        if (k != j && dp[i][k] > dp[i - 1][j] + cost) {
          dp[i][k] = dp[i - 1][j] + cost;
          pr[i][k] = j;
        }
      }
    }
  }
  int mi = min_element(all(dp[n - 1])) - dp[n - 1].begin();
  string ret;
  for (int i = n - 1; i >= 0; --i) {
    ret = (char)('a' + mi) + ret;
    mi = pr[i][mi];
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
