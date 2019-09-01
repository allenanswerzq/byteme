/*
 * created   : 2019-08-04 09:18:18
 * accepted  : 2019-08-04 09:41:46
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

pair<int, int> get(vector<int>& a) {
  int n = a.size();
  pair<int, int> ans;
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] == a[i + 1]) {
      ans.x++;
    }
    else {
      ans.y++;
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  if (n < m) {
    swap(n, m);
  }
  vector<int> a;
  int x = n;
  int y = m;
  int turn = 0;
  a.push_back(0);
  x--;
  for (int i = 0; i < n + m - 1; i++) {
    if (turn == 0) {
      if (y-- > 0) {
        a.push_back(a.back() ^ 1);
      }
      else {
        a.push_back(a.back());
      }
    }
    else {
      if (x-- > 0) {
        a.push_back(a.back());
      }
      else {
        a.push_back(a.back() ^ 1);
      }
    }
    turn ^= 1;
  }
  trace(a);
  pair<int, int> ans = get(a);
  cout << ans.x << " " << ans.y << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
