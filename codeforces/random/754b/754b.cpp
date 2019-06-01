//============================================================================
// Name        : 754b
// Date        : Fri Apr 26 17:02:16 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

char get(vector<string>& a, int x, int y) {
  if (x < 0 || x >= 4) {
    return '$';
  }
  if (y < 0 || y >= 4) {
    return '$';
  }
  return a[x][y];
};

void solve() {
  vector<string> a(4);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  auto check = [&]() {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) {
              continue;
            }
            bool ok = 1;
            for (int k = 0; k < 3; ++k) {
              ok &= (get(a, i + k * dx, j + k * dy) == 'x');
            }
            if (ok) {
              return true;
            }
          }
        }
      }
    }
    return false;
  };
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == '.') {
        a[i][j] = 'x';
        if (check()) {
          output("YES");
          return;
        }
        a[i][j] = '.';
      }
    }
  }
  output("NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

