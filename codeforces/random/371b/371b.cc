/*
 * created   : 2019-07-26 16:57:49
 * accepted  : 2019-07-26 20:06:23
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

vector<int> get(int& x) {
  vector<int> ans(3);
  int k = 0;
  for (int i : {2, 3, 5}) {
    int cnt = 0;
    while (x % i == 0) {
      x /= i;
      cnt++;
    }
    ans[k++] = cnt;
  }
  return ans;
}

void solve() {
  int a, b;
  cin >> a >> b;
  vector<int> ca = get(a);
  vector<int> cb = get(b);
  trace(ca, cb, a, b);
  if (a != b) {
    cout << -1 << "\n";
    return;
  }
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += abs(ca[i] - cb[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
