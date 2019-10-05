/*
 * created   : 2019-07-31 20:08:54
 * accepted  : 2019-07-31 22:09:58
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

struct node {
  int ix;
  int power;
  int coin;
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<node> a(n);
  for (int i = 0; i < n; i++) {
    a[i].ix = i;
    cin >> a[i].power;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].coin;
  }
  sort(a.begin(), a.end(), [](const node& x, const node& y) {
    return x.power < y.power;
  });
  vector<ll> ans(n);
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    ans[a[i].ix] += a[i].coin;
    for (int j = 0; j < min(k, (int) st.size()); j++) {
      ans[a[i].ix] += *next(st.begin(), j);
    }
    st.insert(a[i].coin);
    if ((int) st.size() > k) {
      st.erase(st.begin());
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
