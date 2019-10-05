//=============================================================
// Name        : 173a
// Date        : Sun Jul  7 15:46:08 CST 2019
// Accepted    : Sun Jul  7 16:34:37 CST 2019
// Author      : landcold7
// Description : Action speaks louder more than words
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

int game(char a, char b) {
  if (a == b) {
    return 0;
  }
  else if (a == 'R') {
    return (b == 'S' ? -1 : 1);
  }
  else if (a == 'S') {
    return (b == 'P' ? -1 : 1);
  }
  else if (a == 'P') {
    return (b == 'R' ? -1 : 1);
  }
  else {
    assert(false);
  }
}

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int sa = (int) a.size();
  int sb = (int) b.size();
  int g = sa * sb;
  int ca = 0;
  int cb = 0;
  for (int i = 0; i < g; ++i) {
    int r = game(a[i % sa], b[i % sb]);
    if (r > 0) {
      ca++;
    }
    else if (r < 0) {
      cb++;
    }
  }
  ca = n / g * ca;
  cb = n / g * cb;
  for (int i = 0; i < n % g; ++i) {
    int r = game(a[i % sa], b[i % sb]);
    if (r > 0) {
      ca++;
    }
    else if (r < 0) {
      cb++;
    }
  }
  cout << ca << " " << cb << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
