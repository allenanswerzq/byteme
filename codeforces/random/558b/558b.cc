/*
 * creat   : 2019-07-19 09:12:01
 * accept  : 2019-07-19 09:41:33
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

const int N = 1e6 + 7;
vector<int> cnt(N);
vector<int> st(N, -1);
vector<int> ed(N, -1);

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
    if (st[x] == -1) {
      st[x] = i;
      ed[x] = i;
    }
    else {
      ed[x] = i;
    }
  }
  int mx = *max_element(cnt.begin(), cnt.end());
  pair<int, int> ans;
  int mi = N;
  for (int i = 0; i < N; ++i) {
    if (cnt[i] == mx) {
      int d = ed[i] - st[i] + 1;
      if (d < mi) {
        mi = d;
        ans = {st[i], ed[i]};
      }
    }
  }
  cout << ans.x + 1 << " " << ans.y + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
