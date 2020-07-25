/* created   : 2020-02-09 19:40:13
 * accepted  : 2020-02-09 20:53:25
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve2() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> pr(n + 1);
  for (int i = 0; i < n; i++) {
    pr[i + 1] = pr[i] + a[i];
  }
  auto sum = [&](int l, int r) {
    return pr[r + 1] - pr[l];
  };
  set<pair<ll, int>> st;
  for (int i = k; i + k <= n; i++) {
    st.insert({-sum(i, i + k - 1), i});
  }
  ll ans = 0;
  pair<int, int> pos;
  for (int i = 0; i + 2 * k <= n; i++) {
    ll sa = sum(i, i + k - 1);
    auto tp = *st.begin();
    if (sa - tp.x > ans) {
      ans = sa - tp.x;
      pos = {i, tp.y};
    }
    trace(i, sa, tp, ans, st);
    int next = i + k;
    st.erase({-sum(next, next + k - 1), next});
  }
  cout << pos.x + 1 << ' ' << pos.y + 1 << '\n';
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> pr(n + 1);
  for (int i = 0; i < n; i++) {
    pr[i + 1] = pr[i] + a[i];
  }
  auto sum = [&](int l, int r) {
    return pr[r + 1] - pr[l];
  };
  ll ans = 0;
  pair<int, int> pos;
  ll bestb_val = sum(n - k, n - 1);
  int bestb_pos = n - k;
  for (int i = n - 2 * k; i >= 0; i--) {
    ll sa = sum(i, i + k - 1);
    if (sa + bestb_val >= ans) {
      ans = sa + bestb_val;
      pos = {i, bestb_pos};
    }
    int last = i + k - 1;
    ll sm = sum(last, last + k - 1);
    if (sm > bestb_val) {
      bestb_val = sm;
      bestb_pos = last;
    }
    else if (sm == bestb_val && last < bestb_pos) {
      bestb_pos = last;
    }
    else {
    }
  }
  cout << pos.x + 1 << ' ' << pos.y + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
