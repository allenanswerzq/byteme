//=============================================================
// Name        : 53c
// Date        : Mon Jun  3 10:27:28 CST 2019
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
  int n;
  cin >> n;
  int lo = 1, hi = n;
  int turn = 0;
  while (lo <= hi) {
    if (turn % 2 == 0) {
      cout << lo << " ";
    } else {
      if (lo != hi) {
        cout << hi << " ";
      }
      lo++, hi--;
    }
    turn ^= 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
