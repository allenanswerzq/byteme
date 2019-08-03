/*
 * created   : 2019-07-24 21:23:50
 * accepted  : 2019-07-24 21:50:01
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

int send(int x, int y) {
#ifndef LOCAL
  cout << "? " << x << " " << y << endl;
  int ret;
  cin >> ret;
  return ret;
#else
  vector<int> real = {4, 15, 23, 8, 16, 42};
  return real[x - 1] * real[y - 1];
#endif
}

void solve() {
  vector<int> a = {4, 8, 15, 16, 23, 42};
  map<int, pair<int, int>> mp;
  for (int i = 0; i < 6; ++i) {
    for (int j = i + 1; j < 6; ++j) {
      mp[a[i] * a[j]] = {a[i], a[j]};
    }
  }
  vector<int> ans(7);
  for (int i = 1; i <= 3; i += 2) {
    int x = send(i, i + 1);
    int y = send(i + 1, i + 2);
    trace(x, y, mp[x], mp[y]);
    if (mp[x].x == mp[y].x || mp[x].x == mp[y].y) {
      ans[i + 1] = mp[x].x;
      ans[i] = mp[x].y;
      ans[i + 2] = y / mp[x].x;
    }
    else {
      ans[i + 1] = mp[x].y;
      ans[i] = mp[x].x;
      ans[i + 2] = y / mp[x].y;
    }
  }
  int mul = 1;
  for (int i = 0; i < 6; ++i) {
    mul *= a[i];
  }
  int cur = 1;
  for (int i = 1; i < 7; ++i) {
    if (ans[i] > 0) {
      cur *= ans[i];
    }
  }
  for (int i = 1; i < 7; ++i) {
    if (ans[i] == 0) {
      ans[i] = mul / cur;
    }
  }
  cout << "!";
  for (int i = 1; i < 7; ++i) {
    if (i >= 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
