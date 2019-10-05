//=============================================================
// Name        : 78b
// Date        : Sat Jun  1 10:46:47 CST 2019
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
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  string ret;
  for (int i = 0; i < (n - 1) / 4; ++i) {
    ret += "ROYG";
  }
  int z = sz(ret);
  if (n % 4 == 0) {
    ret += "BIYV";
  } else if (n % 4 == 1) {
    ret[z - 1] = 'B';
    ret[z - 2] = 'I';
    ret += 'V';
  } else if (n % 4 == 2) {
    ret[z - 1] = 'B';
    ret += "IV";
  } else {
    ret += "BIV";
  }
  for (int i = 0; i < n; ++i) {
    set<char> st;
    for (int j = 0; j < 4; ++j) {
      st.insert(ret[(i + j) % n]);
    }
    assert(sz(st) == 4);
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
