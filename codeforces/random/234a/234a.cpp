//=============================================================
// Name        : 234a
// Date        : Mon Jun  3 12:03:43 CST 2019
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n / 2; ++i) {
    int a = i, b = n / 2 + i;
    if (s[a] == 'R') {
      cout << b + 1 << " " << a + 1 << "\n";
    } else {
      cout << a + 1 << " " << b + 1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
