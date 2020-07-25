/* created   : 2020-02-29 23:23:30
 * accepted  : 2020-03-01 11:23:14
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

void solve() {
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << 1 << ' ' << 1 << '\n';
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int> st;
  bool ok = false;
  int hi = -1;
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
    if ((int) st.size() == k) {
      ok = true;
      hi = i;
      break;
    }
  }
  if (!ok) {
    cout << -1 << ' ' << -1 << '\n';
    return;
  }
  trace(hi);
  st.clear();
  int lo = -1;
  for (int i = hi; i >= 0; i--) {
    st.insert(a[i]);
    if ((int) st.size() == k) {
      lo = i;
      break;
    }
  }
  // Santiy check
  assert(lo != -1);
  st.clear();
  for (int i = lo + 1; i <= hi - 1; i++) {
    st.insert(a[i]);
  }
  assert((int) st.size() + 2 == k);
  cout << lo + 1 << ' ' << hi + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
