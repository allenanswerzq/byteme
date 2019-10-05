//============================================================================
// Name        : 591b
// Date        : Sun Apr 21 21:55:57 CST 2019
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

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vi> cnt(26);
  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'a'].pb(i);
  }
  for (int i = 0; i < m; ++i) {
    char x, y;
    cin >> x >> y;
    swap(cnt[x - 'a'], cnt[y - 'a']);
  }
  string ret(n, '#');
  for (int i = 0; i < 26; ++i) {
    for (auto x : cnt[i]) {
      ret[x] = (char)(i + 'a');
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
