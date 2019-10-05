//============================================================================
// Name        : a
// Date        : Sun Apr 21 10:56:24 CST 2019
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

void solve(int tc) {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vi> cnt(n, vi(26));
  vector<int> ch(26);
  for (int i = 0; i < n; ++i) {
    ch[s[i] - 'A']++;
    cnt[i] = ch;
  }
  // trace(cnt);
  vector<pii> a(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].x--, a[i].y--;
  }
  auto get = [&](int j, int x, int y) {
    return cnt[y][j] - (x == 0 ? 0 : cnt[x - 1][j]);
  };
  int ret = 0;
  for (int i = 0; i < q; ++i) {
    int one = 0;
    for (int j = 0; j < 26; ++j) {
      int x = get(j, a[i].x, a[i].y);
      // trace(j, a[i].x, a[i].y, x);
      if (x & 1) {
        one++;
      }
    }
    int d = a[i].y - a[i].x + 1;
    // trace(a[i].x, a[i].y, d, one);
    if ((d == 1) || (((d % 2) ^ one) == 0)) {
      ret++;
    }
  }
  cout << "Case #" << tc << ": " << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
