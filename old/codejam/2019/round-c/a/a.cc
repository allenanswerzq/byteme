/*
 * created   : 2019-07-28 10:26:44
 * accepted  : 2019-07-28 13:01:40
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

struct segset {
  set<pair<int, int>> st;
  // Set a maxn value so that we only compare
  // two pairs using the first value.
  const int HI = 1e6 + 7;

  // Finds the neareast position that less than x
  // and not occpuied by any interval.
  int getpre(int x) {
    auto it = st.upper_bound({x, HI});
    if (it == st.begin()) {
      return x - 1;
    }
    return (--it)->x - 1;
  }

  // Finds the neareast position that greater than x
  // and not occpuied by any interval.
  int getnxt(int x) {
    auto it = st.upper_bound({x, HI});
    if (it == st.begin()) {
      return x + 1;
    }
    return (--it)->y + 1;
  }

  void insert(int x) {
    int lo = x;
    int hi = x;
    auto it = st.lower_bound({x, HI});
    if (it != st.end()) {
      if (it->x == x + 1) {
        hi = it->y;
        st.erase(it);
      }
    }
    it = st.lower_bound({x, HI});
    if (it != st.begin()) {
      it--;
      if (it->y == x - 1) {
        lo = it->x;
        st.erase(it);
      }
    }
    st.insert({lo, hi});
  }
};

void solve(int tc) {
  int n, r, c, sx, sy;
  cin >> n >> r >> c >> sx >> sy;
  string s;
  cin >> s;
  vector<segset> row(r + 1), col(c + 1);
  auto merge = [&](int x, int y) {
    row[x].insert(y);
    col[y].insert(x);
  };
  merge(sx, sy);
  // trace(row, col);
  for (int i = 0; i < n; ++i) {
    // trace(s[i], sx, sy, row, col);
    if (s[i] == 'N') {
      sx = col[sy].getpre(sx);
    }
    else if (s[i] == 'S') {
      sx = col[sy].getnxt(sx);
    }
    else if (s[i] == 'E') {
      sy = row[sx].getnxt(sy);
    }
    else {
      sy = row[sx].getpre(sy);
    }
    merge(sx, sy);
    trace(sx, sy);
  }
  cout << "Case #" << tc << ": ";
  cout << sx << " " << sy << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve(i);
  }
  return 0;
}
