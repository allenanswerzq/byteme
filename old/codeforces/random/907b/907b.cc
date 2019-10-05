/*
 * created   : 2019-08-03 21:03:06
 * accepted  : 2019-08-03 22:07:02
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

void solve() {
  vector<vector<vector<string>>> a;
  vector<vector<string>> t(3);
  string in;
  for (int j = 0; j < 11 && getline(cin, in); j++) {
    trace(in);
    if (in.empty()) {
      trace(t);
      a.push_back(t);
      t.clear();
      t.resize(3);
      continue;
    }
    istringstream iss(in);
    string x;
    for (int i = 0; iss >> x; i++) {
      t[i].push_back(x);
    }
  }
  a.push_back(t);
  trace(a);
  int x, y;
  cin >> x >> y;
  int xb = (x - 1) / 3;
  int yb = (y - 1) / 3;
  int xs = (x - 1) % 3;
  int ys = (y - 1) % 3;
  trace(xb, yb, xs, ys);
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == xs && j == ys) {
        for (int k = 0; k < 3; k++) {
          for (int w = 0; w < 3; w++) {
            if (a[i][j][k][w] == '.') {
              cnt++;
              a[i][j][k][w] = '!';
            }
          }
        }
      }
    }
  }
  if (cnt == 0) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          for (int w = 0; w < 3; w++) {
            if (a[i][j][k][w] == '.') {
              a[i][j][k][w] = '!';
            }
          }
        }
      }
    }
  }
  trace(a);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cout << a[i][k][j] << (k == 2 ? "\n" : " ");
      }
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
