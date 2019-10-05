//=============================================================
// Name        : 88a
// Date        : Mon Jun  3 22:11:24 CST 2019
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
typedef vector<int> vi;

void solve() {
  vector<string> notes = {
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H",
  };
  map<string, int> mp;
  for (int i = 0; i < sz(notes); ++i) {
    mp[notes[i]] = i;
  }
  vector<string> a(3);
  cin >> a[0] >> a[1] >> a[2];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (i == j || i == k || j == k) {
          continue;
        }
        int x = (mp[a[j]] - mp[a[i]] + 12) % 12;
        int y = (mp[a[k]] - mp[a[j]] + 12) % 12;
        if (x == 4 && y == 3) {
          cout << "major\n";
          return;
        } else if (x == 3 && y == 4) {
          cout << "minor\n";
          return;
        }
      }
    }
  }
  cout << "strange\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
