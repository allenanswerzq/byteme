//=============================================================
// Name        : 887b
// Date        : Fri Jun 28 15:53:32 CST 2019
// Accepted    : Fri Jun 28 16:19:15 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<set<int>> a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      int x;
      cin >> x;
      a[i].insert(x);
    }
  }
  for (int i = 1; i < 1000; ++i) {
    vector<int> d;
    int t = i;
    while (t) {
      d.push_back(t % 10);
      t /= 10;
    }
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    bool ok = 0;
    do {
      int cnt = 0;
      for (int j = 0; j < sz(d); ++j) {
        if (a[seq[j]].count(d[j])) {
          cnt++;
        }
      }
      if (cnt == sz(d)) {
        ok = 1;
        break;
      }
    } while(next_permutation(seq.begin(), seq.end()));
    if (!ok) {
      cout << i - 1 << "\n";
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
