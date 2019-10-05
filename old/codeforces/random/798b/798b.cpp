//=============================================================
// Name        : 798b
// Date        : Thu Jun 13 16:01:43 CST 2019
// Accepted    : Thu Jun 13 16:15:39 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

vector<string> get(string& a) {
  vector<string> ans;
  string b = a;
  ans.push_back(a);
  while (true) {
    b.push_back(*b.begin());
    b.erase(b.begin());
    if (b == a) {
      break;
    }
    ans.push_back(b);
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<string>> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    a[i] = get(s);
  }
  trace(a);
  const int inf = 1e9 + 7;
  int ans = inf;
  for (int k = 0; k < sz(a[0]); ++k) {
    string equal = a[0][k];
    int tmp = k, cnt = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < sz(a[i]); ++j) {
        if (a[i][j] == equal) {
          tmp += j;
          cnt++;
          break;
        }
      }
    }
    if (cnt == n - 1) {
      ans = min(ans, tmp);
    }
  }
  cout << (ans == inf ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
