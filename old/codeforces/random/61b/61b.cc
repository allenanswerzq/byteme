//=============================================================
// Name        : 61b
// Date        : Fri Jul  5 09:15:15 CST 2019
// Accepted    : Fri Jul  5 22:51:42 CST 2019
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

string clean(string& a) {
  string r;
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] != '-' && a[i] != '_' && a[i] != ';') {
      r += tolower(a[i]);
    }
  }
  return r;
}

void solve() {
  vector<string> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
    a[i] = clean(a[i]);
  }
  trace(a);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    x = clean(x);
    trace(x);
    vector<int> b = {0, 1, 2};
    bool ok = 0;
    do {
      string y;
      for (int j = 0; j < 3; ++j) {
        y += a[b[j]];
      }
      if (x == y) {
        ok = 1;
        break;
      }
    } while(next_permutation(b.begin(), b.end()));
    cout << (ok ? "ACC" : "WA") << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
