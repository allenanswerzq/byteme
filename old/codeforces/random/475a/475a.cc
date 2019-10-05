//=============================================================
// Name        : 475a
// Date        : Fri Jun 28 10:36:29 CST 2019
// Accepted    : Fri Jun 28 11:12:46 CST 2019
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
  vector<string> a = {
    "+------------------------+",
    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|",
    "|#.......................|",
    "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
    "+------------------------+"
  };
  for (int j = 0; j < sz(a[0]); ++j) {
    for (int i = 0; i < sz(a); ++i) {
      if (n > 0 && a[i][j] == '#') {
        a[i][j] = 'O';
        n--;
      }
    }
  }
  for (auto t : a) {
    cout << t << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
