//============================================================================
// Name        : 370a
// Date        : Wed May 29 15:31:06 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
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
typedef pair<int, int> pii;

void solve() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  if (r1 == r2 || c1 == c2) {
    cout << 1 << " ";
  } else {
    cout << 2 << " ";
  }
  if (abs(r1 - r2) == abs(c1 - c2)) {
    cout << 1 << " ";
  } else if ((abs(r1 - r2) + abs(c1 - c2)) % 2 == 1) {
    cout << 0 << " ";
  } else {
    cout << 2 << " ";
  }
  cout << max(abs(r1 - r2), abs(c1 - c2)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
