//=============================================================
// Name        : 645a
// Date        : Mon Jun  3 15:01:14 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  string a;
  string x, y;
  cin >> x >> y;
  for (int i = 0; i < 2; ++i) {
    if (x[i] != 'X') {
      a += x[i];
    }
  }
  for (int i = 1; i >= 0; --i) {
    if (y[i] != 'X') {
      a += y[i];
    }
  }
  string b;
  cin >> x >> y;
  for (int i = 0; i < 2; ++i) {
    if (x[i] != 'X') {
      b += x[i];
    }
  }
  for (int i = 1; i >= 0; --i) {
    if (y[i] != 'X') {
      b += y[i];
    }
  }
  trace(a, b);
  for (int i = 1; i <= 3; ++i) {
    string pr = a.substr(0, i);
    string sf = a.substr(i);
    if (sf + pr == b) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
